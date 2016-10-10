#include <iostream>

using namespace std;

int try_matching(int boys, int girls, int *boys_skills, int *girls_skills);

int main()
{
  int boys, girls;
  cin >> boys;
  int boys_skills[101];
  int girls_skills[101];
  for (int i = 1; i <= 100; ++i) {
    boys_skills[i] = 0;
    girls_skills[i] = 0;
  }
  int temp;
  for (int i = 0; i < boys; ++i) {
    cin >> temp;
    ++boys_skills[temp];
  }
  cin >> girls;
  for (int i = 0; i < boys; ++i) {
    cin >> temp;
    ++girls_skills[temp];
  }

  int matches = 0;
  for (int i = 1; i <= 100; ++i) {
    matches += try_matching(i, i-1, boys_skills, girls_skills);
    matches += try_matching(i, i, boys_skills, girls_skills);
    matches += try_matching(i, i+1, boys_skills, girls_skills);
  }

  cout << matches << endl;

  return 0;
}

int try_matching(int boys, int girls, int *boys_skills, int *girls_skills)
{
  int matches = 0;
  if (boys_skills[boys] > 0 && girls_skills[girls] > 0) {
    if (girls_skills[girls] > boys_skills[boys]) {
      matches += boys_skills[boys];
      girls_skills[girls] -= boys_skills[boys];
    } else {
      matches += girls_skills[girls];
      boys_skills[boys] -= girls_skills[girls];
      girls_skills[girls] = 0;
    }
  }

  return matches;
}
