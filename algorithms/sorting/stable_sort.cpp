#include <stdio.h>
#include <algorithm>

using namespace std;

struct Point {
  Point() : x(0), y(0), id(0) {};
  Point(int x, int y, int id) : x(x), y(y), id(id) {};

  int id;
  int x;
  int y;
};

void show_point_array(Point points[], int size)
{
  char column1[] = "Points";
  char column2[] = "x";
  char column3[] = "y";
  printf("%10s %10s %10s\n", column1, column2, column3);
  for (int i = 0; i < size; ++i) {
    printf("%10d %10d %10d\n", points[i].id, points[i].x, points[i].y);
  } 
}

bool compare_by_x(Point a, Point b)
{
  return (a.x < b.x);
}

bool compare_by_y(Point a, Point b)
{
  return (a.y < b.y);
}

int main()
{
  Point points[] = {Point(4,5, 1), Point(4,6, 0), Point(6, 4, 2)};
  stable_sort(points, points+3, compare_by_x);
  stable_sort(points, points+3, compare_by_y);
  show_point_array(points, 3);

  return 0;
}
