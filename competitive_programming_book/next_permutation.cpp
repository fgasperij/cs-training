#include <iostream>
#include <vector>

using namespace std;

void print_all_permutations(vector<int> &current, vector<int> &left);
void print_vector(const vector<int> &a);

int main() {
  vector<int> a(5);
  a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5;
  vector<int> current;
  print_all_permutations(current, a);

  return 0;
  
}

void print_vector(const vector<int> &a) {
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i];
  }
  cout << '\n';
}

void print_all_permutations(vector<int> &current, vector<int> &left) {
  if (left.size() == 0) {
    print_vector(current);
    return;
  }

  vector<int>::iterator it;
  for (int i = 0; i < left.size(); ++i) {
    current.push_back(left.back());
    left.pop_back();
    print_all_permutations(current, left);
    it = left.begin();
    left.insert(it, current.back());
    current.pop_back();
  }


  return;
}

