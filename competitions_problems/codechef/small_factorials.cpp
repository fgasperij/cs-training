#include <iostream>
#include <vector>

std::vector<int> multiply(std::vector<int> v, int n)
{
  int carry = 0, temp = 0;
  for (int i = 0; i < v.size(); ++i) {
    carry = v[i] * n + temp;
    temp = carry / 10;
    v[i] = carry % 10;
  }

  while(temp > 0) {
    v.push_back(temp % 10);
    temp /= 10;
  }

  return v;
}

std::vector<int> factorial(int n)
{
  std::vector<int> big_number(1,1);
  for (int i = 2; i <= n; ++i) {
    big_number = multiply(big_number, i);
  }

  return big_number;
}

void print_big_number(std::vector<int> v)
{
  for (int i = v.size()-1; i >= 0; --i) {
    std::cout << v[i];
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) 
{
  int test_cases;
  std::cin >> test_cases;

  int k;
  for (int i = 0; i < test_cases; ++i) {
    std::cin >> k;
    std::vector<int> big_factorial = factorial(k);
    print_big_number(big_factorial);
  }

  return 0;
}
