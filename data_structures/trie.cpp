#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Trie {
  Trie() : words(0), prefixes(0) {};
  int words;
  int prefixes;
  map<char, Trie> children;

  void insert(string word, int i);
  int count_words(string word, int i);
};

void Trie::insert(string word, int i) {
  if (i >= word.size()) {
    ++words;
    return;
  }

  ++prefixes;
  children[word[i]].insert(word, i+1);
  return;
}

int Trie::count_words(string word, int i) {
  if (i >= word.size()) {
    return words;
  }

  if (children.find(word[i]) == children.end()) {
    return 0;
  }

  return children[word[i]].count_words(word, i+1);
}

struct Trie2 {
  map<char, int> children;
  bool ends;
};

Trie2 t[1000];
int sz;
void insert(string s) {
  int node = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (t[node].children.count(s[i]) > 0) {
      node = t[node].children[s[i]];
    } else {
      t[node].children[s[i]] = sz;
      t[sz].children.clear();
      t[sz].ends = false;
      node = sz;
      ++sz;
    }
  }

  t[node].ends = true;
}

void init() {
  sz = 1;
  t[0].children.clear();
  t[0].ends = false;
}

bool check(string s) {
  int node = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (t[node].children.count(s[i]) == 0) {
      return false;
    }
    node = t[node].children[s[i]];
  }
  return t[node].ends;
}

int main() {
  Trie t;
  t.insert("holas", 0);
  t.insert("holas", 0);
  t.insert("hola", 0);
  t.insert("horas", 0);
  t.insert("lalo", 0);

  if (t.count_words("holas", 0) != 2) {
    cout << "ERROR\n";
  }
  if (t.count_words("hola", 0) != 1) {
    cout << "ERROR\n";
  }
  if (t.count_words("horas", 0) != 1) {
    cout << "ERROR\n";
  }
  if (t.count_words("lalo", 0) != 1) {
    cout << "ERROR\n";
  }

  init();
  insert("holas");
  insert("hora");
  insert("hola");
  insert("lalo");

  if (!check("holas")) {
    cout << "ERROR\n";
  }
  if (!check("hora")) {
    cout << "ERROR\n";
  }
  if (!check("hola")) {
    cout << "ERROR\n";
  }
  if (!check("lalo")) {
    cout << "ERROR\n";
  }

  return 0;
}
