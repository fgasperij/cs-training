/*
 * started: 20:31
 * ac:
 * */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int hash_word(string s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res <<= 5;
    res += s[i]-'a'+1;
  }
  return res;
}

int main() {
  bool first = true;
  while (!cin.eof()) {
    if (!first) {
      cout << '\n';
    } else {
      first = false;
    }
    string s;
    vector<int> words;
    vector<string> line;
    while (cin.peek() != '\n') {
      cin >> s;
      line.push_back(s);
      int nword = hash_word(s);
      words.push_back(nword);
    }

    sort(words.begin(), words.end(), greater<int>());

    int n = words.size();
    bool collides = true;
    int c = words[n-1];
    while (collides) {
      collides = false;
      for (int i = 0; i < n && !collides; ++i) {
        for (int j = i+1; j < n && !collides; ++j) {
          int fi = (c/words[i]) % n;
          int fj = (c/words[j]) % n;
          if (fi == fj) {
            collides = true;
            c = min( ((c/words[i])+1)*words[i] , ((c/words[j])+1)*words[j] );
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << line[i];
      if (i < n-1) cout << " ";
    }
    cout << '\n' << c << '\n';

    cin >> ws;
  }

  return 0;
}
