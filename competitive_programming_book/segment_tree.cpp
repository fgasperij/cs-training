#include <vector>

using namespace std;

class SegmentTree {
  private:
    vector<int> st;
    vector<int> A;
    int n;
    int left(int p);
    int right(int p);
    void build(int p, int l, int r);
    int rmq(int p, int l, int r, int i, int j);

  public:
    SegmentTree(const vector<int> &A);
    int rmq(int i, int j);
}

SegmentTree::SegmentTree(const vector<int> &A) {
}


int main() {
  return 0;
}
