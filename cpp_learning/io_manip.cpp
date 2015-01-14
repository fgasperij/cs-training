#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  ifstream fin("io_manip.in");
  string name, last_name;
  fin >> name;
  while(!fin.eof()) {
    cout << name << '\n';
    fin >> name;
  }

  return 0;
}
