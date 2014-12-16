#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
  int MAX_LENGTH = 100001;
  int sequence_length;
  cin >> sequence_length;

  vector<long long int> buckets(MAX_LENGTH, 0LL);
  long long int temp;
  for (int i = 0; i < sequence_length; ++i) {
    cin >> temp;
    ++buckets[temp];
  }

  vector<long long int> dp(MAX_LENGTH, 0LL);
  long long int max_profit;
  dp[1] = buckets[1] * 1LL;
  max_profit = dp[1];
  for (int i = 2; i < MAX_LENGTH; ++i) {
    dp[i] = max(dp[i-1], dp[i-2] + buckets[i]*i);
    max_profit = max(dp[i], max_profit);
  }

  cout << max_profit << endl;

  return 0;
}
