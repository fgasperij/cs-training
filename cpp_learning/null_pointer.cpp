#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> give_me_vector() {
  vector<int> v = vector<int>();
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  return v;
}

int main() {
  vector<int> v = give_me_vector();

  for(int i = 0; i<v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';

  return 0;

}
