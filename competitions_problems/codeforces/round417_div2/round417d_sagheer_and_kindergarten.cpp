#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int crying(const vector<vector<int> >& graph, int start, vector<bool>& visited) {
  stack<int> next;
  next.push(start);
  bool has_cycle = false;
  int nodes = 0;
  while (next.size() > 0) {
    ++nodes;
    int curr = next.top();
    next.pop();
    if (visited[curr]) {
      continue;
    }
    visited[curr] = true;

    for (int i = 0; i < graph[curr].size(); ++i) {
      int neigh = graph[curr][i];
      if (visited[neigh]) {
        has_cycle = true;
      } else {
        next.push(neigh);
      }
    }
  }

  if (has_cycle) {
    return nodes;
  } else {
    return -1;
  }
}

int main() {
  int children, toys, requests, queries;
  cin >> children >> toys >> requests >> queries;

  vector<int> last_for_toy(toys + 1, -1);
  vector<vector<int> > dependencies(children + 1, vector<int>());
  int child, toy;
  for (int i = 0; i < requests; ++i) {
    cin >> child >> toy;
    if (last_for_toy[toy] != -1) {
      dependencies[last_for_toy[toy]].push_back(child);
    }
    last_for_toy[toy] = child;
  }

  vector<bool> visited(child + 1, false);
  for (int i = 0; i < queries; ++i) {
    cin >> child >> toy;

    bool toy_available = last_for_toy[toy] == -1;
    if (toy_available) {
      cout << "0" << endl;
      continue;
    }

    dependencies[last_for_toy[toy]].push_back(child);
    for (int k = 0; k <= children; ++k) {
      visited[k] = false;
    }

    int crying_childs = crying(dependencies, child, visited);
    if (crying_childs == -1) {
      cout << '0' << endl;
    } else {
      cout << crying_childs << endl;
    }

    dependencies[last_for_toy[toy]].pop_back();
  }

  return 0;
}