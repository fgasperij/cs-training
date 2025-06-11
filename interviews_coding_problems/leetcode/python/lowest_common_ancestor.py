from typing import Tuple

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# start reading: 14.13
# finished reading: 14.15
# finished ideas:
# finished coding: 14.28
# accepted: 14.34


# ideas

# idea 1:

# start at the root
# call recursively on both sides
# return if p is present, if q is present, lca node

# questions
# - what happens if root is none?
# - what if p or q are none?
# - what if p or q are not part of the same tree?

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.lca = None
        self.p = p
        self.q = q
        self.rec_lca(root)

        return self.lca

    def rec_lca(self, root: 'TreeNode') -> Tuple[bool, bool]:
        if self.lca is not None:
            return (False, False)

        if root is None:
            return (False, False)
        
        left_has_p, left_has_q = self.rec_lca(root.left)
        right_has_p, right_has_q = self.rec_lca(root.right)

        root_has_p = left_has_p or right_has_p or root == self.p
        root_has_q = left_has_q or right_has_q or root == self.q

        if root_has_p and root_has_q and self.lca is not None:
            self.lca = root

        return (root_has_p, root_has_q)
        