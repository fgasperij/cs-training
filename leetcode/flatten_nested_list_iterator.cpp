#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

struct Data {
  vector<NestedInteger>* l;
  int i;
  Data(vector<NestedInteger>* ptr, int index) : l(ptr), i(index) {};
};

class NestedIterator {

  private:
    stack<Data> s;

  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      s.push(Data(&nestedList, 0));
    }

    void remove_invalid() {
      Data current = s.top();
      while (current.l->size() <= current.i) {
        s.pop();
        current = s.top();
      }
    }

    int next() {
      if (s.empty()) return 0;
      remove_invalid();
      Data current = s.top();
      ++current.i;
      if (current.l[current.i-1].isInteger()) 
        return current.l[current.i-1].getInteger();

      s.push(Data(&current.l[current.i-1], 0));

      return next();
    }

    bool hasNext() {
      remove_invalid();
      return !s.empty();
    }
};

/**
 *  * Your NestedIterator object will be instantiated and called as such:
 *   * NestedIterator i(nestedList);
 *    * while (i.hasNext()) cout << i.next();
 *     */
