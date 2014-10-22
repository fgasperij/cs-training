// to ac: 1:20:45
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

struct Point {
 Point() : x(0), y(0) {};
 Point(int x, int y) : x(x), y(y) {};

 int x;
 int y;
};

int main ()
{
  int n;
  cin >> n;

  list<Point> points;
  int x,y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    points.push_back(Point(x, y));
  }
    
  int cc = 0;
  while(!points.empty()) {
    cc++;
    set<int> xs;
    set<int> ys;
    xs.insert(points.front().x);
    ys.insert(points.front().y);
    points.pop_front();

    bool found = true;
    while (found) {
      found = false;
      list<Point>::iterator it=points.begin();
      while (it != points.end() && !found) {
        if (xs.count((*it).x)) {
          ys.insert((*it).y);
          it = points.erase(it);
          found = true;
        } else {
          if (ys.count((*it).y)) {
            xs.insert((*it).x);
            it = points.erase(it);
            found = true;
          } else {
            it++;
          }
        }
      }
    }
  }

  cout << (cc > 0 ? cc-1 : cc) << endl;

  return 0;
}
