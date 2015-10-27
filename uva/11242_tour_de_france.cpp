/*
 * started: 17:42
 * ac: 
 * */

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
  int f, r;
  cin >> f;
  while (f) {
    cin >> r;
    vector<double> front(f);
    for (int i = 0; i < f; ++i) {
      cin >> front[i];
    }
    vector<double> rear(r);
    for (int i = 0; i < r; ++i) {
      cin >> rear[i];
    }

    vector<double> drive_ratios;
    for (int i = 0; i < f; ++i) {
      for (int j = 0; j < r; ++j) {
        drive_ratios.push_back(rear[j]/front[i]);
        //cout << rear[j]/front[i] << '\n';
      }
    }

    sort(drive_ratios.begin(), drive_ratios.end());

    double max_spread = 0;
    for (int i = 0; i < drive_ratios.size()-1; ++i) {
      max_spread = max(max_spread, drive_ratios[i+1]/drive_ratios[i]);
    }

    printf("%.2f\n", max_spread);

    cin >> f;
  }
  return 0;
}
