#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 15, 23, 24, 32};

  int *lower_bound_index = lower_bound(arr, arr+10, 20);
  cout << "lower bound: " << lower_bound_index-arr << " value: " << *lower_bound_index << endl;

  return 0;
}
