#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct Foot {
  int size;
  int smell;

  string to_str() const {
    stringstream ss;
    ss <<  size << " " << smell;
    return ss.str();
  }

  Foot(int si, int sm) : size(si), smell(sm) {};
};

bool compare_foot(const Foot& a, const Foot& b) {
  return max(a.size, a.smell) < max(b.size, b.smell);
}

typedef bool (*less_than_foo_comp)(const Foot&, const Foot&);

int main() {
  priority_queue<Foot, vector<Foot>, less_than_foo_comp> pq(compare_foot);
  Foot f1(1, 3);
  Foot f2(3, 4);

  pq.push(f1);
  pq.push(f2);

  while (!pq.empty()) {
    cout << pq.top().to_str() << '\n';
    pq.pop();
  }

  return 0;
}
