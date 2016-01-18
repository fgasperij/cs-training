#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main() {
  string S = "abckiabcba";
  string T = "abc";
  unordered_map<char, int> counts;
    for (int i = 0; i < T.size(); ++i) {
        if (counts.find(T[i]) == counts.end()) {
            counts[T[i]] = 1;
        } else {
            ++counts[T[i]];
        }
    }
    int l = -1, left = T.size();
    int minl = 0, minr = S.size();
    for (int i = 0; i < S.size(); ++i) {
        if (counts.find(S[i]) == counts.end()) continue;
        if (l == -1) l = i;
        if (counts[S[i]] > 0) --left;
        --counts[S[i]];
        if (left == 0 && minr-minl > i-l) { 
            minl = l; minr = i;
        }
        if (S[l] == S[i] && counts[S[i]] < 0) {
            int j = l+1;
            cout << "before while ";
            while (counts.find(S[j]) == counts.end() ||
                   counts[S[j]] < 0) {
                if (counts.find(S[j]) != counts.end()) ++counts[S[j]];
                ++j;
            }
            cout << "after while ";
            l = j;
        }
        if (left == 0 && minr-minl > i-l) { 
            minl = l; minr = i;
        }
    }
    cout << " out of loop ";
    
    string res;
    if (minr == S.size()) cout << "RES: " << res;
    
    for (int i = minl; i <= minr; ++i) {
        res += S[i];
    }
    cout << "RES: " << res;
    return 0;
}
