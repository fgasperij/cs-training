#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
  double x;
  double y;
};

struct Line
{
  double a;
  double b;
  bool vertical;
  double x_vertical;
  bool horizontal;
  double y_horizontal;
};

bool intersect_within_interval(Line first, Line second, double left, double right, double down, double up);

int main()
{
  Point home, university;
  cin >> home.x >> home.y;
  cin >> university.x >> university.y;

  int i_roads;
  cin >> i_roads;

  vector<Line> roads(i_roads);
  double a, b, c;
  for (int i = 0; i < i_roads; ++i) {
    cin >> a >> b >> c;
    if (b == 0) {
      roads[i].vertical = true;
      roads[i].x_vertical = (-1.0) * (c/a);
    } else if (a == 0) {
      roads[i].horizontal = true;
      roads[i].y_horizontal = (-1.0) * (c/b);
    } else {
      roads[i].a = (-1.0) * (a/b);
      roads[i].b = (-1.0) * (c/b);
    }
  }


  int crosses = 0;
  Line path;
  if (home.x == university.x) {
    path.vertical = true;
    path.x_vertical = home.x;
  } else if (home.y == university.y) {
    path.horizontal = true;
    path.y_horizontal = home.y;
  } else {
    path.a = (home.y - university.y) / (home.x - university.x);
    double y_growth = path.a * abs(home.x);
    path.b = (home.x > 0) ? (home.y - y_growth) : (home.y + y_growth);
  }
  double left = (home.x < university.x) ? home.x : university.x;
  double right = (home.x > university.x) ? home.x : university.x;
  double down = (home.y < university.y) ? home.y : university.y;
  double up = (home.y > university.y) ? home.y : university.y;

  for (int i = 0; i < roads.size(); ++i) {
    if (intersect_within_interval(path, roads[i], left, right, down, up)) {
      ++crosses;
    }
  }

  cout << crosses << endl;

  return 0;
}

bool intersect_within_interval(Line first, Line second, double left, double right, double down, double up)
{
  if ((first.vertical && second.vertical) || (first.horizontal && second.horizontal)) {
    return false;
  }

  if (first.vertical && second.horizontal) {
    return (second.y_horizontal > down && second.y_horizontal < up);
  }

  if (first.horizontal && second.vertical) {
    return (second.x_vertical > left && second.x_vertical < right);
  }

  if (second.vertical) {
    return (second.x_vertical > left && second.x_vertical < right);
  }

  if (second.horizontal) {
    return (second.y_horizontal > down && second.y_horizontal < up);
  }

  if (first.vertical) {
    int val = (second.a*first.x_vertical) + second.b;
    return (val > down && val < up);
  }
  if (first.horizontal) {
    int val = (first.y_horizontal-second.b)/second.a;
    return (val > left && val < right);
  }

  if ((first.a - second.a) == 0) {
    return false;
  }

  double x_intersect = (first.b - second.b) / (second.a - first.a);
  bool within_interval = (x_intersect > left) && (x_intersect < right);

  return within_interval;
}
