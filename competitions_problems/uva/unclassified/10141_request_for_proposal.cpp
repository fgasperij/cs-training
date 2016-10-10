#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Proposal {
  string name;
  float price;
  int met_requirements;
};

bool compare_compliance(Proposal p1, Proposal p2)
{
  return (p1.met_requirements > p2.met_requirements);
}

bool compare_price(Proposal p1, Proposal p2)
{
  return (p1.price < p2.price);
}

int main()
{
  int i_requirements, i_proposals, rfp = 1;
  string dev_null;
  cin >> i_requirements >> i_proposals;
  while (i_requirements != 0 || i_proposals != 0) {
    if (rfp > 1) {
      cout << endl;
    }
    getline(cin, dev_null);
    for (int i = 0; i< i_requirements; ++i) {
      getline(cin, dev_null);
    }

    vector<Proposal> proposals(i_proposals);
    for (int i = 0; i < i_proposals; ++i) {
      getline(cin, proposals[i].name);
      cin >> proposals[i].price >> proposals[i].met_requirements;
      getline(cin, dev_null);
      for (int j = 0; j < proposals[i].met_requirements; ++j) {
        getline(cin, dev_null);
      }
    }

    stable_sort(proposals.begin(), proposals.end(), compare_price);
    stable_sort(proposals.begin(), proposals.end(), compare_compliance);

    cout << "RFP #" << rfp << endl;
    cout << proposals[0].name << endl;

    ++rfp;
    cin >> i_requirements >> i_proposals;
  }

  return 0;
}
