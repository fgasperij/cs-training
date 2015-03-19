#include <iostream>

using namespace std;

int main()
{
  int height, width;
  cin >> height >> width;
  while (height > 0 && width > 0) {
    int step_height, previous_step_height, turned_on_times = 0;
    cin >> previous_step_height;
    for (int i = 1; i < width; ++i) {
      cin >> step_height;
      if (step_height > previous_step_height) {
        turned_on_times += (step_height-previous_step_height);
      }
      previous_step_height = step_height;
    }
    turned_on_times += (height-previous_step_height);

    cout << turned_on_times << endl;

    cin >> height >> width;
  }

  return 0;
}
