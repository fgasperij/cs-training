#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class FenwickTree {

  private:
    vector<int> ft;
    int max;
    int LSOne(int i);

  public:
    FenwickTree(int n) : ft(vector<int> (n+1, 0)), max(n) {};
    void adjust(int index, int value);
    int rsq(int i);
    int rsq(int i, int j);
    int read_single(int i);
    int smallest_index_with_frequency(int f);
};

int FenwickTree::LSOne(int i) {
  return i & -i;
}

void FenwickTree::adjust(int index, int value) {
  while (index <= max) {
    ft[index] += value;
    index += (index & -index);
  }
}

int FenwickTree::rsq(int i) {
  int acum = 0;
  while (i > 0) {
    acum += ft[i];
    i -= LSOne(i);
  }

  return acum;
}

int FenwickTree::smallest_index_with_frequency(int f) {
  // TODO
  int left = 1;
  int right = max + 1;


  return 0;

}

int FenwickTree::rsq(int i, int j) {
  if (i > j) {
    return rsq(i) - rsq(j);
  }
  return rsq(j) - rsq(i);
}

int FenwickTree::read_single(int i) {
  if (i % 2) {
    return ft[i];
  }

  int start = i-1;
  int finish = i - LSOne(i) + 1;
  int result = ft[i];
  while (start >= finish) {
    result -= ft[start];
    start -= LSOne(start);
  } 

  return result;
}


int main() {
  // TODO tests
  return 0;
}
