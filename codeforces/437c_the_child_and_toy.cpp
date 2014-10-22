// to ac: 1:02:14
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  Node() : value(0), index(0) {};
  Node(int v,int i) : value(v), index(i) {};

  int value;
  int index;
};

class compare_node {
  public:
    bool operator() (const Node& l, const Node& r) const 
    {
      return l.value < r.value;
    }
};

int main() 
{
  int n, m, temp;
  cin >> n >> m;
  vector<int> values;
  vector<bool> alive;
  priority_queue<Node, vector<Node>, compare_node> nodes;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    nodes.push(Node(temp, i));
    values.push_back(temp);
    alive.push_back(true);
  }
  
  vector<vector<int> > adjacents(n);
  int k, j;
  for (int i = 0; i < m; i++) {
    cin >> k >> j;
    adjacents[k-1].push_back(j-1);
    adjacents[j-1].push_back(k-1);
  }

  Node current_node;
  int current_adjacent;
  int acum = 0;
  for (int i = 0; i < n-1; i++) {
    current_node = nodes.top();
    nodes.pop();
    alive[current_node.index] = false;
    for (int j = 0; j < adjacents[current_node.index].size(); j++) {
      current_adjacent =  adjacents[current_node.index][j];
      if (alive[current_adjacent]) {
        acum += values[current_adjacent];
      }
    }
  }

  cout << acum << endl;
    
  return 0;
}
