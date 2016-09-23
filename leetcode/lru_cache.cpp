#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

typedef list<int>::iterator lii;

struct Entry {
  int value;
  lii it;
  Entry(int v, lii an_it) : value(v), it(an_it) {};
  Entry() : value(0), it(lii()) {};
};

class LRUCache{
  public:

    int c;
    unordered_map<int, Entry> table;
    list<int> usage;

    LRUCache(int capacity) {
      c = capacity;
    }

    int get(int key) {
      if (table.count(key) == 0) return -1;

      Entry& e = table[key];
      use(e, key);

      return e.value;
    }

    void use(Entry& e, int key) {
      usage.erase(e.it);
      usage.push_front(key);
      e.it = usage.begin();
    }

    void set(int key, int value) {
      if (table.count(key) > 0) {
        Entry& e = table[key];
        use(e, key);
        e.value = value;
        return;
      }
      if (table.size() == c) {
        table.erase(usage.back());
        usage.pop_back();
      }
      usage.push_front(key);
      table[key] = Entry(value, usage.begin());
    }
};
