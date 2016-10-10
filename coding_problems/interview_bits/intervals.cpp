#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
  if (newInterval.start > newInterval.end) {
    swap(newInterval.start, newInterval.end);
  }
  vector<Interval> merged_ints;
  Interval current = intervals[0];
  int i = 0;
  while (!(max(current.start, newInterval.start) < min(current.end, newInterval.end)) &&
    current.start < newInterval.start && i < intervals.size()) {
    merged_ints.push_back(current);
    ++i;
    current = intervals[i];
  }
  if (i == intervals.size()) {
    merged_ints.push_back(newInterval);
    return merged_ints;
  } else if (current.start > newInterval.end) {
    merged_ints.push_back(current);
  } else {
    Interval merged_int;
    merged_int.start = min(current.start, newInterval.start);
    int end;
    while (max(current.start, newInterval.start) < min(current.end, newInterval.end)) {
      end = max(current.end, newInterval.end);
      ++i;
      current = intervals[i];
    }
    merged_int.end = end;
    merged_ints.push_back(merged_int);
  }

  while (i < intervals.size()) {
    merged_ints.push_back(current);
    ++i;
    current = intervals[i];
  }

  return merged_ints;
}

int main() {
  Interval a(1, 2);
  Interval b(3, 6);
  Interval c(8, 10);

  vector<Interval> v;
  v.push_back(a);
  v.push_back(b);

  vector<Interval> v1 = insert(v, c);

  cout << "[";
  for (int i = 0; i < v1.size(); ++i) {
    cout << "(" << v1[i].start << ", " << v1[i].end << ") "; 
  }
  cout << "]\n";
  
  return 0;
}
