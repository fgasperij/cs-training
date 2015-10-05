#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// MAX HEAP

void bubble_down(vector<int> &A, int current) {
  int left_child = current*2;
  int right_child = current*2 + 1;
  // leaf
  if (left_child >= A.size()) return;
  // just left child
  if (right_child >= A.size() && A[current] < A[left_child]) {
    swap(A[current], A[left_child]);
    return;
  }
  // both children
  int max_child = A[left_child] > A[right_child] ? left_child : right_child;
  if (A[max_child] > A[current]) {
    swap(A[current], A[max_child]);
    bubble_down(A, max_child);
  }

  return;
}

void heapify_ext(vector<int> &A, int current) {
  if(current >= A.size()) return;

  int left_child = current*2;
  int right_child = current*2 + 1;
  heapify_ext(A, left_child);
  heapify_ext(A, right_child);

  bubble_down(A, current);
}

void heapify(vector<int> &A) {
  heapify_ext(A, 1);
}

int top(vector<int> &A) {
  if (A.size() > 1) {
    return A[1];
  }

  return -1;
}

void pop(vector<int> &A) {
  A[1] = A[A.size()-1];
  A.pop_back();
  bubble_down(A, 1);
}

int main() {

  vector<int> A(5);
  A.push_back(0);
  A.push_back(4);
  A.push_back(1);
  A.push_back(3);
  A.push_back(6);
  A.push_back(2);

  heapify(A);
  cout << "A: ";
  for (int i = 0; i < A.size()-1; ++i) {
    cout << top(A) << " ";
    pop(A);
  }
  cout << '\n';

  return 0;
}
