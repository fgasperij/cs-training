#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "The file, Willy!" << endl;
    return 1;
  }

  string filename(argv[1]);
  stringstream ss;
  ss << argv[2];
  int k;
  ss >> k;

  ifstream fin(filename);
  vector<string> v(k);
  int i = 0;
  string tmp;
  while (!getline(fin, tmp).eof()) {
    v[i%k] = tmp;
    ++i;
  }

  int j = 0;
  while (j < k) {
    if ((i < k && j > k) || (j >= i)) break;
    int index = i >= k ? i+j : j;
    cout << v[index%k] << '\n';
    ++j;
  }

  return 0;
}
