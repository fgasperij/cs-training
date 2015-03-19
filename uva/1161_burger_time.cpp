#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
  int highway_length;
  cin >> highway_length;
  while (highway_length > 0) {
    char place;
    int min_distance = highway_length;
    bool found_z = false;
    bool found_first_r_d = false;
    char last_r_d = ' ';
    int accum_distance = 0;
    for (int i = 0; i < highway_length && !found_z; ++i) {
      cin >> place;
      if (place == 'Z') {
        min_distance = 0;
        found_z = true;
        cin.ignore(numeric_limits<int>::max(), '\n');
      } else if (place == '.') {
        ++accum_distance;
      } else if (found_first_r_d && last_r_d != place && place != '.') {
        min_distance = min(accum_distance+1, min_distance);
      }
      if (place == 'R' || place == 'D') {
        found_first_r_d = true;
        last_r_d = place;
        accum_distance = 0;
      }
    }

    cout << min_distance << endl;

    cin >> highway_length;
  }

  return 0;
}
