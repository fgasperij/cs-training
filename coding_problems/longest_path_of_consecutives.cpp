// tags: dp tree
// from: career_cup

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  int val;
  Node* right;
  Node* left;
  Node(int v, Node* r, Node* l) : val(v), right(r), left(l) {};
};

void bt_dfs(Node* root, int current_length, int next, int &max_length) {
  if (root == NULL) return;
  if (root->val == next) {
    ++current_length;
    max_length = max(current_length, max_length);
  } else {
    current_length = 1;
  }

  bt_dfs(root->right, current_length, root->val+1, max_length);
  bt_dfs(root->left, current_length, root->val+1, max_length);
}

int main() {
  Node* root = new Node(1, NULL, NULL);
  root->left = new Node(2, NULL, NULL);
  root->right = new Node(4, NULL, NULL);
  root->right->left = new Node(5, NULL, NULL);
  root->right->left->right = new Node(6, NULL, NULL);
  root->right->left->right->left = new Node(7, NULL, NULL);
  root->left->left = new Node(3, NULL, NULL);
  root->left->right = new Node(5, NULL, NULL);

  int max_length = 0;
  bt_dfs(root, 0, root->val, max_length);

  cout << "Maximum length of a path of consecutives is " << max_length << '\n';

  return 0;
}
