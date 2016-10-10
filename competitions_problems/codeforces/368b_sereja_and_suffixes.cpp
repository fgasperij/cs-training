#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
  int numbers_size, queries;
  cin >> numbers_size >> queries;

  vector<int> numbers (numbers_size+1);
  for (int i = 1; i <= numbers_size; ++i) {
    cin >> numbers[i];
  }

  set<int> counting_set;
  vector<int> distinct (numbers_size+1);
  distinct[numbers_size] = 1;
  counting_set.insert(numbers[numbers_size]);
  for (int i = numbers_size-1; i > 0; --i) {
    pair<set<int>::iterator, bool> insertion = counting_set.insert(numbers[i]);
    distinct[i] = distinct[i+1];
    if (insertion.second) {
      ++distinct[i];
    }
  } 

  int query;
  for (int i = 0; i < queries; ++i) {
    cin >> query;
    cout << distinct[query] << '\n';
  }

  return 0;
}
