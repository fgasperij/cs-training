#include <stdio.h>

int main()
{
  const int MAX_COURSES = 10000;
  int i_courses, i_categories;
  int courses[MAX_COURSES];
  scanf("%d", &i_courses);
  while (i_courses > 0) {
    for(int i = 0; i < MAX_COURSES; ++i) {courses[i] = false;}
    scanf("%d", &i_categories);
    int selected_course;
    for (int i = 0; i < i_courses; ++i) {
      scanf("%d", &selected_course);
      courses[selected_course] = true;
    }
    bool all_categories_met = true;
    for (int i = 0; i < i_categories; ++i) {
      int courses_in_category, courses_required, selected_courses = 0, category_course;
      scanf("%d %d", &courses_in_category, &courses_required);
      for(int j = 0; j < courses_in_category; ++j) {
        scanf("%d", &category_course);
        if (courses[category_course]) {
          ++selected_courses;
        }
      }
      if (selected_courses < courses_required) {
        all_categories_met = false;
      }
    }

    if (all_categories_met) {
      printf("yes\n");
    } else {
      printf("no\n");
    }

    scanf("%d", &i_courses);
  }

  return 0;
}

