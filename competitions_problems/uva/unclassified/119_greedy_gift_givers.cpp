#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Balance {
  int give;
  int take;
};

int main()
{
  int i_groups;
  bool first = true;
  cin >> i_groups;
  while(!cin.eof()) {
    if (!first) {
      cout << endl;
    } else {
      first = false;
    }
    map<string, Balance> balances;
    vector<string> names;
    string name;
    for (int i = 0; i < i_groups; ++i) {
      cin >> name;
      balances[name].take = 0;
      balances[name].give = 0;
      names.push_back(name);
    }
    int total_money_spent, gifts_given, per_gift_money;
    for (int i = 0; i < i_groups; ++i) {
      cin >> name >> total_money_spent >> gifts_given;
      if (total_money_spent > 0) {
        if (gifts_given > 0) {
          balances[name].give = total_money_spent;
          balances[name].give -= total_money_spent % gifts_given;
        }
      }
      if (total_money_spent > 0 || gifts_given > 0) {
        for (int j = 0; j < gifts_given; ++j) {
          cin >> name;
          balances[name].take += total_money_spent/gifts_given;
        }
      }
    }

    for (int i = 0; i < names.size(); ++i) {
      name = names[i];
      cout << name << ' ' << balances[name].take - balances[name].give << endl;
    }
    cin >> i_groups;
  }

  return 0;
}
