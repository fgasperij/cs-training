#include <iostream>
#include <vector>
#include <algorithm>

int square_prime(int n);
int p (int a, int b, int dp[]);
std::vector<int> generate_sieve(int);

int main() {
  int cases;
  std::cin >> cases;

  std::vector<int> sieve = generate_sieve(10000);
  std::vector<int> squares;
  int i = 1;
  while (i*i < 10000) {
    squares.push_back(i*i);
    i++;
  }
  std::vector<int> squares_sum;
  for (int i = 0; i < squares.size(); i++) {
    for (int j = i+1; j < squares.size(); j++) {
      if (squares[i] % 2 != squares[j] % 2) {
        squares_sum.push_back(squares[i]+squares[j]);
      }
    }
  }

  std::vector<int> squares_sum_primes;
  for (int i = 0; i < squares_sum.size(); i++) {
    if (sieve[squares_sum[i]]) {
      squares_sum_primes.push_back(squares_sum_primes[i]);
    }
  }

  sort(squares_sum_primes.begin(), squares_sum_primes.end());

  std::vector<vector<int> > dp(10000, vector<int> (8, -1));

  for (int i = 0; i < cases; i++) {
    int n, a, b;
    std::cin >> n >> b;

    a = squares_sum_primes[n];
    std::cout << p(a, b, dp) << std::endl;
  }

  return 0;
}

std::vector<int> generate_sieve(int n)
{
  const int is_prime = 1;
  const int is_not_prime = 0;
  std::vector<int> sieve(n, 1);
  sieve[1] = 0;

  for(int i = 0; i < n; i++) {
    if (sieve[i] == is_prime) {
      int j = i+i;
      while(j < n) {
        sieve[j] = is_not_prime;
        j += i;
      }
    }
  }

  return sieve;
}

int p (int a, int b, vector<int> dp) 
{
  if (dp[a][b] == -1) {
    dp[a][b] = p(a, b-1, dp) + p(a-b, b, dp);
  }
  
  return dp[a][b];
}
