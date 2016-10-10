#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

int dfs(int root, vector<list<int> > adjacents, vector<int> depth) {
  stack<int> nodes_left;
  nodes_left.push(root);

  int height = 1, current, child;
  while (!nodes_left.empty()) {
    current = nodes_left.top();
    nodes_left.pop();
    while(!adjacents[current].empty()) {
      child = adjacents[current].front();
      depth[child] = depth[current] + 1;

      if (depth[child] > height) {
        height = depth[child];
      }
      nodes_left.push(child);
      adjacents[current].pop_front();
    }
  }

  return height;
}

int main() {
  const int autonomous = -1;

  int employees;
  cin >> employees;

  vector<list<int> > adjacents(employees);
  vector<int> depth(employees, -1);
  list<int> roots;
  
  int manager;
  for (int i = 0; i < employees; i++) {
    cin >> manager;
    if (manager != autonomous) {
      adjacents[manager-1].push_back(i);
    } else {
      roots.push_back(i);
      depth[i] = 1;
    }
  }

  int current, length, max = 0;
  while (!roots.empty()) {
    length = dfs(roots.front(), adjacents, depth);
    if (length > max) {
      max = length;
    }
    roots.pop_front();
  }

  cout << max << endl;

  return 0;
}
