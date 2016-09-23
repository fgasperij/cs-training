#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode* lnp;

lnp merge(lnp l, lnp r) {
  lnp merged_head = NULL;
  lnp last_merged = NULL;
  lnp tmp = NULL;
  while (l && r) {
    if (l->val < r->val) {
      tmp = l;
      l = l->next;
    } else {
      tmp = r;
      r = r->next;
    }
    if (last_merged) {
      last_merged->next = tmp;
    } else {
      merged_head = tmp;
    }
    last_merged = tmp;
  }
  if (l) last_merged->next = l;
  if (r) last_merged->next = r;

  return merged_head;
}

ListNode* sortList(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;
  lnp slow = head;
  lnp fast = head->next;
  lnp prev = NULL;
  while (fast) {
    prev = slow;
    slow = slow->next;
    fast = fast->next;
    if (fast) fast = fast->next;
  }

  if (prev) prev->next = NULL;

  lnp left = sortList(head);
  lnp right = sortList(slow);

  return merge(left, right);
}
