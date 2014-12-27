#include <iostream>
#include <vector>

using namespace std;

struct Moment {
  int left;
  int right;
};

int main()
{
  int i_moments, skip;
  cin >> i_moments >> skip;

  vector<Moment> moments(i_moments);
  for (int i = 0; i < i_moments; ++i) {
    cin >> moments[i].left >> moments[i].right;
  }

  int current_minute = 1;
  int watch_time = 0;
  for (int i = 0; i < moments.size(); ++i) {
    Moment current_moment = moments[i];
    watch_time += ((current_moment.left - current_minute) % skip);
    watch_time += (current_moment.right - current_moment.left) + 1;
    current_minute = current_moment.right + 1;
  }

  cout << watch_time << endl;

  return 0;
}
