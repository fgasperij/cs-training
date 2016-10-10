/**
 * 61. Given a list, rotate the list to the right by k places, where k is non-negative.
 */

#include<iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
   
ListNode* rotateRight(ListNode* head, int k) {
  if (head == NULL || head->next == NULL || k == 0) return head;

  ListNode* curr = head;
  int count = 1;
  while (curr->next != NULL) {
    ++count;
    curr = curr->next;
  }

  k = k % count;
  if (k == 0) return head;
  curr->next = head;

  count -= k+1;
  while (count--) head = head->next;
  curr = head->next;
  head->next = NULL;

  return curr;
}
