#include <iostream>

using namespace std;

struct Food {
  int protein;
  int carbo;
  int fat;
};

int main()
{
  int test_cases;
  cin >> test_cases;
  for (int t = 1; t<=test_cases; ++t) {
    Food goal;
    cin >> goal.protein >> goal.carbo >> goal.fat;
    int i_foods;
    cin >> i_foods;

    vector<Food> foods(i_foods);
    for(int f = 0; f<i_foods; ++f) {
      cin >> foods[f].protein >> foods[f].carbo >> foods[f].fat;
    }




  }

  return 0;
}

void bt(vector<Food> foods, vector<int> selected_foods, bool &found, Food total_values, int next_food) {
  if (found) {
    return;
  }

  for(int i = next_food; i < foods.size(); ++i) {
    Food food_to_add = foods[i];
    if (food_to_add.proteing + total_values.protein <= 
  } 
}

