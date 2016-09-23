#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

typedef vector<ListNode*> vls;

static bool comp_nodes (const ListNode* a, ListNode* b) {
  return a->val > b->val;
}

void populate(vls& nodes_heap, vls& v) {
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] != NULL) {
      nodes_heap.push_back(v[i]);
      push_heap(nodes_heap.begin(), nodes_heap.end(), comp_nodes);
    }
  }
}

ListNode* mergeKLists(vls& lists) {
  vls nodes_heap;
  populate(nodes_heap, lists);
  ListNode* next, *last_merged = NULL, *merged_head;
  while (!nodes_heap.empty()) {
    next = nodes_heap[0];
    pop_heap(nodes_heap.begin(), nodes_heap.end(), comp_nodes);
    nodes_heap.pop_back();
    if (last_merged == NULL) {
      merged_head = next;
    } else {
      last_merged->next = next;
    }
    last_merged = next;
    if (next->next != NULL) {
      nodes_heap.push_back(next->next);
      push_heap(nodes_heap.begin(), nodes_heap.end(), comp_nodes);
    }
  }

  return merged_head;
}
