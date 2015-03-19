#include <vector>

using namespace std;

class UnionFind {

  private:
    vector<int> p;
    vector<int> rank;
    vector<int> sizes;
    int sets;

  public:
    UnionFind(int n);
    int findSet(int i);
    bool isSameSet(int i, int j);
    void unionSet(int i, int j);
    int disjointSets();
    int sizeOfSet(int i);
};

UnionFind::UnionFind(int n) { 
  sets = n;
  rank.assign(n, 0);
  p.assign(n, 0);
  sizes.assign(n, 1);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
}

int UnionFind::findSet(int i) {
  return (i == p[i] ? i : p[i] = findSet(p[i]));
}

bool UnionFind::isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}

void UnionFind::unionSet(int i, int j) {
  // r_i root of i
  if (!isSameSet(i, j)) {
    int r_i = findSet(i);
    int r_j = findSet(j);

    if (rank[r_i] > rank[r_j]) {
      p[r_j] = r_i; // height does not increase
      sizes[r_i] += sizes[r_j];
    } else {
      p[r_i] = r_j;
      sizes[r_j] += sizes[r_i];
      if (rank[r_i] == rank[r_j]) {
        ++rank[r_j];
      }
    }
    --sets;
  }
}

int UnionFind::disjointSets() {
  return sets;
}

int UnionFind::sizeOfSet(int i) {
  return sizes[findSet(i)];
}

int main() {
  return 0;
}

