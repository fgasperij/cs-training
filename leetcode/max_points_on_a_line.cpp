/**
 * 149. Max points on a line. Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

int gcda(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0) return a;
  return gcda(b, a%b);
}
string hashme(int num, int den) {
  int sign = den*num >= 0 ? 1 : -1;
  den = abs(den);
  num = abs(num);
  int gcdb = gcda(num, den);
  num /= gcdb;
  den /= gcdb;

  return to_string(num*sign)+"/"+to_string(den); 
}
int maxPoints(vector<Point>& points) {
  unordered_multiset<string> pendings;
  int max_line = 0;
  for (int i = 0; i < points.size(); ++i) {
    pendings.clear();
    Point p1 = points[i];
    int same = 1;
    int local_max = 0;
    for (int j = i+1; j < points.size(); ++j) {
      Point p2 = points[j];    
      if (p2.x == p1.x && p2.y == p1.y) {
        ++same;
        continue;
      }
      string hashit = hashme(p2.y-p1.y, p2.x-p1.x);
      pendings.insert(hashit);
      local_max = max((int)pendings.count(hashit), local_max);
    }
    max_line = max(local_max+same, max_line);
  }

  return max_line;
}
