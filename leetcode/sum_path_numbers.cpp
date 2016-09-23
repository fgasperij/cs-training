/**
 * 129. Sum root to leaf numbers
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int pathSums(TreeNode* n, int psum) {
  if (n == NULL) return 0;
  psum = (psum*10)+n->val;
  if (n->left == NULL && n->right == NULL) return psum;
  return pathSums(n->left, psum) + pathSums(n->right, psum);
}

int sumNumbers(TreeNode* root) {
  return pathSums(root, 0);
}
