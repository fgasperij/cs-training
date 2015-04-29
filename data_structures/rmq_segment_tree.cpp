#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

void print_vector(const vector<int> &A);

class RMQSegmentTree {
  private:
    vector<int> st;
    vector<int> A;
    int n;

    int left(int p);
    int right(int p);
    void build(int p, int l, int r);
    int rmq(int p, int l, int r, int i, int j);
    int get_p(int a_index);
    int get_parent(int child);

  public:
    RMQSegmentTree(const vector<int> &A);
    int rmq(int i, int j);
    void update(int index, int value);
    vector<int> get_a();
};

RMQSegmentTree::RMQSegmentTree(const vector<int> &A) {
  this->A = A;
  n = A.size();
  st.assign(4*n, 0);
  build(1, 0, n-1);
}

vector<int> RMQSegmentTree::get_a() {
  return A;
}

void RMQSegmentTree::build(int p, int l, int r) {
  if (l == r) {
    // base case
    st[p] = l;
    return;
  } 

  int l_child = left(p);
  int r_child = right(p);
  build(l_child, l, (r+l)/2);
  build(r_child, (r+l)/2 + 1, r);
  if ( A[st[l_child]] < A[st[r_child]] ) {
    st[p] = st[l_child];
  } else {
    st[p] = st[r_child];
  }
}

int RMQSegmentTree::rmq(int p, int l, int r, int i, int j) {
  if (l >= i && r <= j) {
    return st[p];
  }
  if (j < l || i > r) {
    return -1;
  }

  int min_l = rmq(left(p), l, (l+r)/2, i, j);
  int min_r = rmq(right(p), (l+r)/2 + 1, r, i, j);

  if (min_l == -1) return min_r;
  if (min_r == -1) return min_l;

  return (A[min_l] < A[min_r]) ? min_l : min_r;
}

int RMQSegmentTree::rmq(int i, int j) {
  return rmq(1, 0, n-1, i, j);
}

int RMQSegmentTree::left(int p) {
  return p << 1;
}

int RMQSegmentTree::right(int p) {
  return (p << 1) + 1;
}

int RMQSegmentTree::get_p(int i) {
  int l = 0;
  int r = n-1;
  int p = 1;
  while (l != r) {
    if (i >= l && i <= (l+r)/2) {
      r = (l+r)/2;
      p = left(p);
    } else {
      l = (l+r)/2 + 1;
      p = right(p);
    }
  }

  return p;
}

int RMQSegmentTree::get_parent(int p) {
  int parent = p >> 1;
  return parent;
}

void RMQSegmentTree::update(int index, int value) {
  A[index] = value;
  int p = get_p(index);
  st[p] = index;

  int parent = get_parent(p);
  int l_child, r_child;
  // TODO we could reduce the number of nodes visited by stopping
  // the bubbling if a parent is not updated.
  while (parent) {
    l_child = st[left(parent)];
    r_child = st[right(parent)];
    st[parent] = A[l_child] < A[r_child] ? l_child : r_child;
    parent = get_parent(parent);
  }
}

void print_vector(const vector<int> &A) {
  cout << "A: ";
  for (int i = 0; i < A.size(); ++i) {
    cout << A[i] << " ";
  }
  cout << '\n';
}

int linear_rmq(const vector<int> &A, int i, int j) {
  int min = i;
  for (int s = i+1; s<=j; ++s) {
    if (A[s] < A[min]) {
      min = s;
    }
  }

  return min;
}

void test_all_queries(const vector<int> &A, RMQSegmentTree &st) {
  cout << "TESTING ALL QUERIES" << endl;
  for (int i = 0; i < A.size(); ++i) {
    for (int j = i; j < A.size(); ++j) {
      int res = st.rmq(i, j);
      int linear = linear_rmq(A, i, j);
      cout << "rmq(" << i << ", "<< j << ") = " << res << ". It should be " << linear << ".";
      if (linear != res) {
        cout << " WRONG!";
      }
      cout << "\n";
    }
  }
  cout << "\n";
} 

int main() {
  vector<int> A;
  A.push_back(18); A.push_back(17); A.push_back(13); A.push_back(19); A.push_back(15); A.push_back(11); A.push_back(20);

  RMQSegmentTree st = RMQSegmentTree(A);

  test_all_queries(A, st);

  st.update(3, 2);
  A[3] = 2;
  test_all_queries(A, st);

  return 0;
}
