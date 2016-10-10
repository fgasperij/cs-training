#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vint;

struct Node{
  Node() : row(-1), column(-1) {};
  Node(int i, int j) : row(i), column(j) {};
  int row;
  int column;
};

bool dfs(Node, vector<vector<bool> >, vector<int>, vector<int>);

int main(int argc, char *argv[])
{
  int n, m;
  cin >> n >> m;

  vector<int> row_directions(n, 0);
  vector<int> column_directions(m, 0);
  getchar();
  for (int i = 0; i < n; ++i) {
    if (getchar() == '>') {
      row_directions[i] = 1;
    } else {
      row_directions[i] = -1;
    }
  }
  getchar();
  for (int i = 0; i < m; ++i) {
    if (getchar() == 'v') {
      column_directions[i] = 1;
    } else {
      column_directions[i] = -1;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vector<vector<bool> > visited(n, vector<bool> (m, false));
      if (!dfs(Node(i, j), visited, row_directions, column_directions)) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;

  return 0;
}

bool dfs(Node node, vector<vector<bool> > visited, vint row_directions, vint column_directions)
{
  int visited_nodes = 0;
  int rows = row_directions.size();
  int columns = column_directions.size();
  stack<Node> nodes_left;
  nodes_left.push(node);
  visited[node.row][node.column] = true;
  Node current_node;

  while (!nodes_left.empty()) {
    current_node = nodes_left.top();
    nodes_left.pop();
    ++visited_nodes;

    int new_row = current_node.row + column_directions[current_node.column];
    int new_column = current_node.column + row_directions[current_node.row];
    if (new_row < rows && new_row >= 0) {
      if (!visited[new_row][current_node.column]) {
        visited[new_row][current_node.column] = true;
        nodes_left.push(Node(new_row, current_node.column));
      }
    }
    if (new_column < columns && new_column >= 0) {
      if (!visited[current_node.row][new_column]) {
        visited[current_node.row][new_column] = true;
        nodes_left.push(Node(current_node.row, new_column));
      }
    }
  }

  bool reached_all = visited_nodes == rows*columns;
  return reached_all;
}
