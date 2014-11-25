#include <iostream>
#include <iomanip>

int main()
{
  int withdrawal;
  float balance;
  std::cin >> withdrawal >> balance;

  if (withdrawal % 5 != 0 || withdrawal+0.5 > balance) {
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << balance << std::endl;
  } else {
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << balance-(withdrawal+0.5) << std::endl;
  }

  return 0;
}
