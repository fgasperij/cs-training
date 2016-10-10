#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string decrypt(const string &encrypted, int offset) {
  string decrypted;
  for (int i = 0; i < encrypted.length(); ++i) {
    int current;
    if (encrypted[i] == ' ') {
      current = 0;
    } else {
      current = encrypted[i]-'A'+1;
    }
    int moved_val = (current - offset + 27) % 27;
    decrypted.push_back((moved_val == 0 ? ' ' : (moved_val+'A'-1)));
  }
  
  return decrypted;
}

int main() {
  unordered_set<string> dictionary;
  string word;
  cin >> word;
  while (word != "#") {
    dictionary.insert(word);
    cin >> word;
  }

  cin.ignore(100000, '\n');
  string encrypted_message;
  getline(cin, encrypted_message);

  int max_count = 0;
  string max_decrypted;
  for (int i = 0; i < 27; ++i) {
    string decrypted = decrypt(encrypted_message, i);
    int count = 0;
    bool found = true;
    int word_start = 0;
    int word_end;
    while (found) {
      word_end = decrypted.find_first_of(" ", word_start);
      if (word_end == -1) {
        found = false;
      } else {
        count += dictionary.count(decrypted.substr(word_start, word_end-word_start));
        word_start = word_end+1;
      }
    }
    count += dictionary.count(decrypted.substr(word_start, decrypted.size()-word_start));

    if (count > max_count) {
      max_count = count;
      max_decrypted = decrypted;
    }
  }

  int word_start = 0, word_end;
  string line;
  while (word_start < max_decrypted.size()) {
    word_end = max_decrypted.find_first_of(" ", word_start);
    if (word_end == -1) word_end = max_decrypted.size();
    if (line.length() + (word_end-word_start) > 60) {
      cout << line << '\n';
      line.clear();
    }
    if (!line.empty()) line += " ";
    line += max_decrypted.substr(word_start, word_end-word_start);
    word_start = word_end+1;
  }

  if (!line.empty()) cout << line << '\n';

  return 0;
}
