#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool reachable(int s, int d, vector<vector<int> > &ladj)
{
  bool reached = false;
  vector<int> visited (ladj.size(), false);
  visited[s] = true;
  int current;
  stack<int> neighborhood;
  neighborhood.push(s);

  while (!reached && !neighborhood.empty()) {
    current = neighborhood.top();
    neighborhood.pop();
    for (int i = 0; i < ladj[current].size(); ++i) {
      if (ladj[current][i] == d) {
        reached = true;
      }
      if (!visited[ladj[current][i]]) {
        visited[ladj[current][i]] = true;
        neighborhood.push(ladj[current][i]);
      }
    }
  }

  return reached;
}

int main()
{
  int i_nodes, i_edges;
  cin >> i_nodes >> i_edges;
  vector<vector<vector<int> > > edges_by_color(i_edges+1, vector<vector<int> > (i_nodes+1, vector<int> ()));;
  int u, v, c;
  for (int i = 0; i < i_edges; ++i) {
    cin >> u >> v >> c;
    edges_by_color[c][u].push_back(v);
    edges_by_color[c][v].push_back(u);
  }

  /*
  for (int i = 0; i < edges_by_color.size(); ++i) {
    vector<vector<int> > current_color = edges_by_color[i];
    cout << "color " << i << endl;
    for (int j = 0; j < current_color.size(); ++j) {
      cout << "node " << j;
      vector<int> current_node = current_color[j];
      for (int k = 0; k < current_node.size(); ++k) {
        cout << " " << current_node[k];
      }
      cout << endl;
    }
  }
  */

  int queries;
  cin >> queries;
  int s, d;
  for (int i = 0; i < queries; ++i) {
    cin >> s >> d;
    int colors = 0;
    for (int j = 1; j < edges_by_color.size(); ++j) {
      if (reachable(d, s, edges_by_color[j])) {
        ++colors;
      }
    }
    cout << colors << endl;
  }

  return 0;
}
