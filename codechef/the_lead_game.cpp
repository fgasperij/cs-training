#include <iostream>
#include <cmath>

int main()
{
  int rounds, max_lead = 0, round_score_1, round_score_2, 
      winner = 0, overall_1 = 0, overall_2 = 0;

  std::cin >> rounds;

  for (int i = 0; i < rounds; ++i) {
    std::cin >> round_score_1 >> round_score_2;
    overall_1 += round_score_1;
    overall_2 += round_score_2;
    int lead = std::abs(overall_1 - overall_2);
    if (lead > max_lead) {
      winner = (overall_1 > overall_2) ? 1 : 2;
      max_lead = lead;
    }
  }

  std::cout << winner << ' ' << max_lead << std::endl;

  return 0;
}
