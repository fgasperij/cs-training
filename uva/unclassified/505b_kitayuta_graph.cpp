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

  while (!reach && !neighborhood.empty()) {
    current = neighborhood.top();
    neighborhood.pop();
    for (int i = 0; i < ladj[current].size(); ++i) {
      reach = (ladj[current][i] == d);
      if (!visited[ladj[current][i]]) {
        neighborhood.push(ladj[current][i]);
      }
    }
  }

  return reached;
}

int main()
{
  int i_nodes, i_edges;
  cin >> i_nodes, i_edges;
  vector<vector<vector<int> > > edges_by_color(i_edges+1, vector<int> (i_nodes+1, vector<int> ()));;
  int u, v, c;
  for (int i = 0; i < i_edges; ++i) {
    cin >> u >> v >> c;
    edges_by_color[c][u].push_back(v);
    edges_by_color[c][v].push_back(u);
  }

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

  return 0 
}
