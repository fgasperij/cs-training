/*
 * started: 17:26
 * ac: 17:20
 * */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void process_city(string s, map<char, char> &city) {
  for (int i = 0; i < s.size(); i+=4) {
    city[s[i]] = s[i+2];
  }
}

int best_city(vector<map<char, char> > cities) {
  int best_city = 1;
  int min_changes = 100000;
  for (int i = 0; i < cities.size(); ++i) {
    int changes = 0;
    for (int j = 0; j < cities.size(); ++j) {
      string letters = "bogry";
      for (int k = 0; k < 5; ++k) {
        if (cities[i][letters[k]] != cities[j][letters[k]]) ++changes;
      }
    }
    if (changes < min_changes) {
      best_city = i+1;
      min_changes = changes;
    }
  }

  return best_city;
}

int main() {
  string s;
  cin >> s;
  while (s[0] != '#') {
    vector<map<char, char> > cities;
    map<char, char> city;
    while (s[0] != 'e') {
      process_city(s, city);
      cities.push_back(city);

      cin >> s;
    }

    cout << best_city(cities) << '\n';
    cin >> s;
  }

  return 0;
}
