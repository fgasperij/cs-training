#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

struct Event {
  bool is_start;
  int x;
  int height;
  Event(bool s, int x, int h) : is_start(s), height(h), x(x) {};
};

bool mycomp(Event &a, Event &b) {
  if (a.x == b.x) {
    if (a.is_start && !b.is_start) return true;
    if (!a.is_start && b.is_start) return false;
    if (a.is_start) return a.height > b.height;
    return a.height < b.height;
  }
  return a.x < b.x;
}

int main() {
  vector<Event> events;
  int l, h, r;
  cin >> l >> h >> r;
  while (!cin.eof()) {
    events.push_back(Event(true, l, h));
    events.push_back(Event(false, r, h));
    cin >> l >> h >> r;
  }

  sort(events.begin(), events.end(), mycomp);
  vector<pair<int, int> > skyline;
  multiset<int> heights;
  int sky_height = 0;
  for (int i = 0; i < events.size(); ++i) {
    Event e = events[i];
    if (e.is_start) {
      heights.insert(e.height);
      if (e.height > sky_height) {
        skyline.push_back(make_pair(e.x, e.height));
        sky_height = e.height;
      }
    } else {
      multiset<int>::iterator it = heights.find(e.height);
      heights.erase(it);
      if (e.height == sky_height && heights.count(e.height) == 0) {
        sky_height = heights.empty() ? 0 : *(heights.rbegin());
        skyline.push_back(make_pair(e.x, sky_height));
      }
    }
  }

  for (int i = 0; i < skyline.size(); ++i) {
    cout << skyline[i].first << " " << skyline[i].second;
    if (i < skyline.size()-1) cout << " ";
  }
  cout << '\n';

  return 0;
}
