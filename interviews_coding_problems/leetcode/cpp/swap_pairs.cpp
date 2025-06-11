// https://leetcode.com/problems/swap-nodes-in-pairs/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Recursive:

ListNode* swapPairs(ListNode* head) {
  head -> headn -> headnn...
  headn -> head -> swapPairs(headnn..), return headn
  
  if (!head || !head->next);
      return head;
  ListNode* headn = head->next;
  head->next = swapPairs(headn->next);
  headn->next = head;
  return headn;
}

// Iterative: (que feo!)

ListNode* swapPairs(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* backupHead = (head && head->next) ? head->next : head;
  while (head) {
    if (!head->next) {
      if (prev)
        prev->next = head;
    } else {
      ListNode* headn = head->next, *headnn = headn->next;
      headn->next = head;
      head->next = headnn;
      if (prev)
        prev->next = headn;
    }

    prev = head;
    head = head->next;
  }

  return backupHead;
}
