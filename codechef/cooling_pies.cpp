#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int test_cases;
  cin >> test_cases;

  int pies_amount;
  for (int t = 0; t < test_cases; ++t) {
    cin >> pies_amount;
    vector<int> pies(pies_amount);
    vector<int> racks(pies_amount);
    for (int p = 0; p < pies_amount; ++p) {
      cin >> pies[p];
    }
    for (int r = 0; r < pies_amount; ++r) {
      cin >> racks[r];
    }

    sort(pies.begin(), pies.end());
    sort(racks.begin(), racks.end());

    int p = 0;
    int r = 0;
    int located_pies = 0;
    while (p < pies_amount && r < pies_amount) {
      bool found_rack = false;
      while (!found_rack && r < pies_amount) {
        if (pies[p] <= racks[r]) {
          ++located_pies;
          found_rack = true;
        }
        ++r;
      }
      ++p;
    }

    cout << located_pies << endl;
  }

  return 0;
}
