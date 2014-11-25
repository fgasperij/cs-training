#include <iostream>
#include <stack>

int main()
{
  std::stack<int> s;
  s.push(0);
  s.push(0);
  s.push(0);
  s.push(0);

  int& i = s.top();
  ++i;
  ++i;

  //++s.top();
  std::cout << "Top: " << s.top() << std::endl;

  return 0;
}
