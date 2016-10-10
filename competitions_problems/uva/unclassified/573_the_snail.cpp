#include <iostream>

using namespace std;

int main()
{
  double snail_height, well_height, climb_distance, slide_distance, fatigue_percentage, fatigue;
  bool out, dig;
  cin >> well_height;
  while (well_height > 0) {
    out = false;
    dig = false;
    cin >> climb_distance >> slide_distance >> fatigue_percentage;
    fatigue = (fatigue_percentage*climb_distance)/100;
    int day = 0, finish_day;
    snail_height = 0;
    while (!out && !dig) {
      ++day;
      if (climb_distance > 0) {
        snail_height += climb_distance;
        out = snail_height > well_height;
        climb_distance -= fatigue;
      } 
      snail_height -= slide_distance;
      dig = snail_height < 0;
    }

    if (out) {
      cout << "success on day " << day << endl;
    } else {
      cout << "failure on day " << day << endl;
    }

    cin >> well_height;
  }

  return 0;
}
