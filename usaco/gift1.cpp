/*
ID: fgasper2
LANG: C++
TASK: gift1
*/

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");

  int np, npl;
  fin >> np;
  map<string, int> um;
  string name;
  npl = np;
  vector<string> order;
  while (npl--) {
    fin >> name;
    um[name] = 0;
    order.push_back(name);
  }
  npl = np;
  int money, friends, gives;
  while (npl--) {
    fin >> name >> money >> friends;
    if (friends == 0 || money == 0) continue;
    um[name] -= (money - (money % friends));
    gives = money / friends;
    while (friends--) {
      fin >> name;
      um[name] += gives;
    }
  }
  for (int i = 0; i < order.size(); ++i) 
    fout << order[i] << " " << um[order[i]] << '\n';

  return 0;
}
