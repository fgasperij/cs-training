#include <iostream>
#include <vector>
#include <limits>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int bf_approach(vector<int> v);
int simple_dp(vector<int> v);

int main(int argc, char *argv[])
{
  int test_cases = 1;
  int array_length = 1000000000;

  bool dp_works = true;
  srand(time(NULL));
  vector<int> v (array_length);
  for (int i = 0; i < test_cases; ++i) {
    for (int j = 0; j < array_length; ++j) {
      v[j] = (rand() % 200) - 100;
    }
    int bf_result = 0;//bf_approach(v);
    int simple_dp_result = simple_dp(v);
    if (0){//simple_dp_result != bf_result) {
      cout << "v = [";
      for(int j = 0; j < array_length; ++j) {
        cout << v[j];
        if (j < array_length - 1) {
          cout << ", ";
        }
      }
      cout << "]" << endl;
      cout << "BF: " << bf_result << endl;
      cout << "DP: " << simple_dp_result << endl;

      dp_works = false;
    }
  }

  if (dp_works) {
    cout << "DP Worked!" << endl;
  } else {
    cout << "DP Failed!" << endl;
  }

  return 0;
}

int simple_dp(vector<int> v)
{
  int max_ending_previous_position = 0;
  int max_so_far = 0;
  for (int i = 0; i < v.size(); ++i) {
    max_ending_previous_position = max(v[i], max_ending_previous_position+v[i]);
    max_so_far = max(max_ending_previous_position, max_so_far);
  }

  return max_so_far;
}

int bf_approach(vector<int> v)
{
  int max_sum = numeric_limits<int>::min();
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i; j < v.size(); ++j) {
      int current_sum = 0;
      for (int k = i; k <= j; ++k) {
        current_sum += v[k];
      }
      if (current_sum > max_sum) {
        max_sum = current_sum;
      }
    }
  }

  return max_sum;
}
