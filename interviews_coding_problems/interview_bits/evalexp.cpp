#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int main() {
  vector<string> A;
  A.push_back("-2"); A.push_back("-1"); A.push_back("2"); A.push_back("+"); A.push_back("-1"); A.push_back("-"); A.push_back("-");
  A.push_back("2"); A.push_back("-2"); A.push_back("1"); A.push_back("-"); A.push_back("+"); A.push_back("-"); A.push_back("-2");
  A.push_back("-2"); A.push_back("-"); A.push_back("-1"); A.push_back("2"); A.push_back("-2"); A.push_back("-"); A.push_back("-2");
  A.push_back("-1"); A.push_back("+"); A.push_back("1"); A.push_back("1"); A.push_back("-"); A.push_back("-1"); A.push_back("+");
  A.push_back("1"); A.push_back("*"); A.push_back("*"); A.push_back("2"); A.push_back("+"); A.push_back("*"); A.push_back("-");
  A.push_back("-2"); A.push_back("1"); A.push_back("-2"); A.push_back("*"); A.push_back("+"); A.push_back("-2"); A.push_back("*");
  A.push_back("1"); A.push_back("*"); A.push_back("-"); A.push_back("*"); A.push_back("*");
  stack<double> s;
  double r, l;
  for (int i = 0; i < A.size(); ++i) {
    if (isdigit(A[i][0])) {
        cout << "is_digit\n";
        s.push(atof(A[i].c_str()));
    } else {
        cout << "doing_op ";
        if (s.empty()) cout << "EMPTY";
        //r = s.top();
        //s.pop();
        if (s.empty()) cout << "EMPTY";
        //l = s.top();
        //s.pop();
        if (A[i] == "+") {
            cout << "is_plus ";
            //s.push(l+r);    
        } else if (A[i] == "*") {
            cout << "is_prod ";
            //s.push(l*r);
        } else if (A[i] == "-") {
            cout << "is_minus ";
            //s.push(l-r);
        } else if (A[i] == "/") {
            cout << "is_div ";
            if (r < 1e-9) cout << "R IS ZERO";
            //s.push(l/r);
        }
    }
  }
  //  if (s.empty()) cout << "EMPTY";
  //  cout << "RESULT: " <<  s.top();
  //  cout << endl;

  return 0;
}

