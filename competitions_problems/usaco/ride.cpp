/*
ID: fgasper2
LANG: C++
TASK: ride
*/

#include <fstream>
#include <string>
#include <numeric>

using namespace std;

int char_prod(const int accum, const char elem) {
  return accum*(((int)(elem-'A'))+1);
}

int name_to_number(string name) {
  int prod = 1;
  return accumulate(name.begin(), name.end(), prod, char_prod);
}

int main() {
  ifstream fin("ride.in");
  ofstream fout("ride.out");

  string comet_name, group_name;
  fin >> comet_name >> group_name;

  int comet_number, group_number;
  comet_number = name_to_number(comet_name);
  group_number = name_to_number(group_name);

  if (comet_number % 47 == group_number % 47) {
    fout << "GO";
  } else {
    fout << "STAY";
  }
  fout << endl;

  return 0;
}
