#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> A;
  A.push_back("This");
  A.push_back("is");
  A.push_back("an");
  A.push_back("example");
  A.push_back("of");
  A.push_back("text");
  A.push_back("justification.");
  int B = 14;
  vector<string> lines;
  vector<string> words;
  int i = 0;
  while (i < A.size()) {
      words.clear();
      int line_length = 0;
      while (i < A.size() && A[i].size() + line_length <= B) {
          words.push_back(A[i]);
          line_length += A[i].size() + 1;
          ++i;
      }
      if (i == A.size()) continue;
      string line;
      if (words.size() == 1) {
          line += words[0];
          while (line.size() < B) line += " ";
          lines.push_back(line);
          continue;
      }
      --line_length;
      int left_over = B-line_length;
      int slots = words.size()-1;
      int spaces = left_over/slots+1;
      int rest = left_over % slots;
      
      for (int j = 0; j < words.size()-1; ++j) {
          line += words[j];
          for(int k = 0; k < spaces; ++k) line += ' ';
          if (rest > 0) {
              line += ' ';
              --rest;
          }
      }
      line += words[words.size()-1];
      lines.push_back(line);
  }
  
  string line;
  for (int j = 0; j < words.size(); ++j) {
      line += words[j];
      if (j < words.size()-1) line += ' ';
  }
  while (line.size() < B) line += " ";
      
  lines.push_back(line);
  
  for (int l = 0; l < lines.size(); ++l) {
    cout << lines[l] << '\n';
  }
  return 0;
}


