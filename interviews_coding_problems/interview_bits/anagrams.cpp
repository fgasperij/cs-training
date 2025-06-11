#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    vector<string> A;
    A.push_back("dog");
    A.push_back("god");
    A.push_back("car");
    A.push_back("rac");
    vector<vector<int> > groups;
    //if (A.empty()) return groups;
    vector<bool> classified(A.size(), false);
    for (int i = 0; i < A.size(); ++i) {
        if (classified[i]) continue;
        classified[i] = true;
        vector<int> group;
        group.push_back(i+1);

        unordered_map<char, int> counts;
        string current_string = A[i];
        cout << current_string << endl;
        for (int j = 0; j < current_string.size(); ++j) {
            if (counts.find(current_string[j]) == counts.end()) {
                counts[current_string[j]] = 1;
            } else {
                ++counts[current_string[j]];
            }
        }

        for (int j = i+1; j < A.size(); ++j) {
            current_string = A[j];
            if (current_string.size() != A[i].size() || classified[j]) continue;
            bool is_anagram = true;
            unordered_map<char, int> checker(counts);
            for (int k = 0; k < current_string.size() && is_anagram; ++k) {
                unordered_map<char, int>::iterator it = checker.find(current_string[k]);
              if (it == checker.end() || (*it).second == 0) {
                    is_anagram = false;
                } else {

                --((*it).second);
                }
            }
            if (is_anagram) {
                group.push_back(j+1);
                classified[j] = true;
            }
        }

        groups.push_back(group);
    }
    //return groups;

    for (int i = 0; i < groups.size(); ++i) {
      cout << "[ ";
      for (int j = 0; j < groups[i].size(); ++j) {
        cout << groups[i][j] << " ";
      }
      cout << "]\n";
    }

  return 0;
}
