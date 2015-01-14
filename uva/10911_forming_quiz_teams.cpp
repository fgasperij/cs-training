#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Student
{
  int x;
  int y;
};

void minimum_sum(vector<Student> students, vector<bool> paired, int current_student,
    double &min_distance, double distance_sum);

int main()
{
  int student_pairs;
  cin >> student_pairs;
  int test_case = 1;
  while (student_pairs > 0) {
    vector<Student> students(2*student_pairs);
    string name;
    for (int i = 0; i < 2*student_pairs; ++i) {
      cin >> name >> students[i].x >> students[i].y;
    }

    vector<bool> paired(students.size(), false);
    double min_distance = numeric_limits<double>::max();
    minimum_sum(students, paired, 0, min_distance, 0);
    cout << "Case " << test_case << ": " << setprecision(2) << fixed << min_distance << endl;

    cin >> student_pairs;
    ++test_case;
  }

  return 0;
}

double calculate_distance(Student s1, Student s2)
{
  double distance = sqrt(pow(s1.x-s2.x, 2)+pow(s1.y-s2.y, 2));
  return distance;
}

void minimum_sum(vector<Student> students, vector<bool> paired, int current_student,
    double &min_distance, double distance_sum)
{
  if (current_student == students.size()) {
    min_distance = min(distance_sum, min_distance);
  }

  if (paired[current_student]) {
    minimum_sum(students, paired, current_student+1, min_distance, distance_sum);
    return;
  }

  for (int i = current_student+1; i < students.size(); ++i) {
    if (!paired[i]) {
      double added_distance = calculate_distance(students[current_student], students[i]);
      if (distance_sum+added_distance < min_distance) {
        paired[current_student] = true;
        paired[i] = true;
        minimum_sum(students, paired, current_student+1, min_distance, distance_sum+added_distance);
        paired[current_student] = false;
        paired[i] = false;
      }
    }
  }



   


}
