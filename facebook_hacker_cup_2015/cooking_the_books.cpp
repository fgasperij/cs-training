#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

void print_vector(vector<int> v) 
{
  for(int j = 0; j < v.size(); ++j) {
    cout << v[j];
  }
}

int main()
{
  int test_cases;
  cin >> test_cases;
  for (int t = 1; t <= test_cases; ++t) {
    string number;
    cin >> number;
    
    vector<int> digits (number.length());
    for(int i = 0; i < number.length(); ++i) {
      char temp = number[i];
      digits[i] = atoi(&temp);
    }

    vector<int> smaller = digits;
    bool found_smaller = false;
    int more_significant = 0;
    while (!found_smaller && more_significant < digits.size()-1) {
      int right_min = digits[more_significant];
      int right_min_index = more_significant;
      for(int less_significant = more_significant+1; less_significant < digits.size(); ++less_significant) {
        if (right_min >= digits[less_significant] && 
            !(more_significant == 0 && digits[less_significant] == 0)) {
          right_min = digits[less_significant];
          right_min_index = less_significant;
          found_smaller = true;
        }
      }
      if (found_smaller) {
        smaller[more_significant] = digits[right_min_index];
        smaller[right_min_index] = digits[more_significant];
      }
      ++more_significant;
    }

    vector<int> bigger = digits;
    bool found_bigger = false;
    more_significant = 0;
    while (!found_bigger && more_significant < digits.size()-1) {
      int right_max = digits[more_significant];
      int right_max_index = more_significant;
      for(int less_significant = more_significant+1; less_significant < digits.size(); ++less_significant) {
        if (right_max <= digits[less_significant]) {
          right_max = digits[less_significant];
          right_max_index = less_significant;
          found_bigger = true;
        }
      }
      if (found_bigger) {
        bigger[more_significant] = digits[right_max_index];
        bigger[right_max_index] = digits[more_significant];
      }
      ++more_significant;
    }

    cout << "Case #" << t << ": "; print_vector(smaller); cout << " "; print_vector(bigger); cout << endl;
  }

  return 0;
  
}
