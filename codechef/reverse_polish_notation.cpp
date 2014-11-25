#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <ctype.h>

struct Operation {
  Operation() : first(std::string()), second(std::string()), operand('\0') {};

  std::string to_string()
  {
    std::string result = first + second + operand;
    
    return result;
  };

  std::string first;
  std::string second;
  char operand;
};

bool opens(char c)
{
  return c == '(';
}
bool closes(char c)
{
  return c == ')';
}
bool is_operand(char c)
{
  return c == '*' || c == '+' || c == '/' || c == '^' || c == '-';
}

std::string transform(std::string expression)
{
  std::string result;
  std::stack<Operation> operations;
  char current;
  bool getting_number = false;
  for (int i = 0; i < expression.length(); ++i) {
    current = expression[i];
    if (opens(current)) {
      operations.push(Operation());
    } else if (closes(current)) {
      Operation op = operations.top();
      operations.pop();
      if (operations.empty()) {
        result = op.to_string();
      } else {
        if (operations.top().first.empty()) {
          operations.top().first = op.to_string();
        } else {
          operations.top().second = op.to_string();
        }
      }
    } else if (is_operand(current)) {
      operations.top().operand = current;
    } else if (isalpha(current)) {
      Operation op = operations.top();
      if (op.first.empty()) {
        operations.top().first = current;
      } else {
        operations.top().second = current;
      }
    }
  }

  return result;
}

int main()
{
  int test_cases;
  std::cin >> test_cases;

  std::string expression, result;
  for (int i = 0; i < test_cases; ++i) {
    std::cin >> expression;
    result = transform(expression);
    std::cout << result << std::endl;
  }

  return 0;
}
