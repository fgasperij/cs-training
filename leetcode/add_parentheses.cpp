#include <iostream>
#include <vector>
#include <string>

using namespace std;

void parseInput(string &input, vector<char> &operators, vector<int> &operands) {
  int last = 0;
  for (int i = 0; i < input.size(); ++i) {
    char current = input[i];
    if (current == '+' || current == '-' || current == '*') {
      operators.push_back(current);
      operands.push_back(stoi(input.substr(last, i-last)));
      last = i+1;
    }
  }
  operands.push_back(stoi(input.substr(last, input.size()-last)));
}

int operate(int l, int r, char c) {
  if (c == '+') return l+r;
  if (c == '-') return l-r;
  return l*r;
}

vector<int> diffWaysToCompute(string input) {
  vector<char> operators;
  vector<int> operands;
  parseInput(input, operators, operands);
  cout << "Input parsed.";

  int optn = operators.size(), opdn = operands.size();
  vector<vector<vector<int> > > dp(opdn, vector<vector<int> > (opdn, vector<int> ()));

  for (int i = 0; i < opdn; ++i) dp[i][i].push_back(operands[i]);
  for (int diag_length = opdn-1; diag_length > 0; --diag_length) {
    int n = diag_length, row = 0, col = opdn-diag_length;
    while (n--) {
      for (int i = row; i < col; ++i) {
        vector<int> &lways = dp[row][i];
        vector<int> &rways = dp[i+1][col];
        for (int ii = 0; ii < lways.size(); ++ii) {
          for (int jj = 0; jj < rways.size(); ++jj)
            dp[row][col].push_back(operate(lways[ii], rways[jj], operators[i]));
        }
      }
      ++row; ++col;
    }
  }

  return dp[0][opdn-1];
}

int main() {
  string s("0+1");
  vector<int> ways = diffWaysToCompute(s);

  cout << "The different ways to compute " <<  s << " are:\n";
  for (int i = 0; i < ways.size(); ++i) cout << ways[i] << " ";
  cout << '\n';

  return 0;
}

