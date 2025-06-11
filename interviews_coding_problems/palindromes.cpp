#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int bottom_up(string);
int top_down(string s);
bool is_palindrome(string s, int left, int right, vector<vector<int> > &dp);

int main() 
{
  string s("sasas");

  cout << "TopDown approach gets: " << top_down(s) << endl;
  cout << "BottomUp approach gets: " << bottom_up(s) << endl;
}    

int top_down(string s)
{
  // -1 => not set
  // 0  => false
  // 1  => true
  vector<vector<int> > dp(s.length(), vector<int> (s.length(), -1));

  int palindromes = 0;
  for (int i = 0; i < s.length(); ++i) {
    for (int j = i; j < s.length(); ++j) {
      if (is_palindrome(s, i, j, dp)) {
        ++palindromes;
      }
    }
  }

  return palindromes;
}

bool is_palindrome(string s, int left, int right, vector<vector<int> > &dp)
{
  if (dp[left][right] != -1) {
    return (bool)dp[left][right];
  }

  // case base: length 1 palindrome
  if (left == right) {
    dp[left][right] = 1;
    return true;
  }

  // case base: length 2 palindrome
  if (abs(left - right) == 1) {
    if (s[left] == s[right]) {
      dp[left][right] = 1;
      return true;
    } else {
      dp[left][right] = 0;
      return false;
    }
  }

  bool is_a_palindrome = (s[left] == s[right]) && is_palindrome(s, left+1, right-1, dp);
  if (is_a_palindrome) {
    dp[left][right] = 1;
    return true;
  } else {
    dp[left][right] = 0;
    return false;
  }
}

int bottom_up(string s)
{
  vector<vector<bool> > dp(s.length(), vector<bool> (s.length()));

  // base cases, length 1 palindromes
  int palindromes = s.length();
  for (int i = 0; i < s.length(); ++i) {
    dp[i][i] = true;
  }

  for (int i = s.length()-2; i >= 0; --i) {
    for (int j = i+1; j < s.length(); ++j) {
      if (abs(i - j) > 1) {
        dp[i][j] = (s[j] == s[i]) && dp[i+1][j-1];
      } else {
        // length 2 palindromes
        dp[i][j] = s[i] == s[j];
      }

      if (dp[i][j]) {
        ++palindromes;
      }
    }
  }

  return palindromes;
}
