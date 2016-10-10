#include <string>
#include <map>

using namespace std;

int main() {
  string card;
  cin >> card;

  map<char, int> suit_count = {{'S', 0}, {'C', 0}, {'H', 0}, {'D', 0}};
  map<char, int> figure_value = {{'A', 4}, {'K', 3}, {'Q', 2}, {'J', 1}};
}
