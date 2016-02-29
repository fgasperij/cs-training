#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;

  Node() {
    val = 0;
    left = NULL;
    right = NULL;
  };
};

int max_depth(Node *root) {
  if (root == NULL) return 0;
  return 1 + max(max_depth(root->left), max_depth(root->right));
}

int min_depth(Node *root) {
  if (root == NULL) return 0;
  return 1 + min(min_depth(root->left), min_depth(root->right));
}

bool is_balanced(Node *root) {
  return abs(max_depth(root)-min_depth(root)) <= 1;
}

int main() {
  Node *a1 = new Node();
  Node *a2 = new Node();
  Node *a3 = new Node();
  Node *a4 = new Node();
  Node *a5 = new Node();
  Node *a6 = new Node();
  Node *a7 = new Node();
  a1->left = a2;
  a2->left = a3;
  a3->left = a4;
  a4->left = a5;
  a1->right = a6;
  a6->left = a7;

  if (is_balanced(a1)) {
    cout << "IS BALANCED\n";
  } else {
    cout << "IS NOT BALANCED\n";
  }

  return 0;
}
