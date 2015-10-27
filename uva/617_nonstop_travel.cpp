/*
 * started: 17:54
 * ac: 18:58
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

struct Light {
  double x;
  int red;
  int yellow;
  int green;
  Light(double x, int r, int y, int g) : x(x), red(r), yellow(y), green(g) {};
};

bool green_at(int v, Light light) {
  double arrival = (light.x*3600)/v;
  double duration = light.red + light.yellow + light.green;
  double rest = fmod(arrival, duration);

  return rest <= light.green + light.yellow;
}

bool all_greens_at(int v, vector<Light> lights) {
  for (int i = 0; i < lights.size(); ++i) {
    if (!green_at(v, lights[i])) return false;
  }

  return true;
}

int main() {
  int n, c = 1;
  cin >> n;
  while (n != -1) {
    vector<Light> lights;
    double x;
    int r, g, y;
    for (int i = 0; i < n; ++i) {
      cin >> x >> g >> y >> r;
      lights.push_back(Light(x, r, y, g));
    }

    vector<int> speeds;
    for (int v = 30; v <= 60; ++v) {
      if (all_greens_at(v, lights)) speeds.push_back(v);
    }

    int left = 0, right = 0, i = 0;
    stringstream speeds_stream;
    while (i < speeds.size()) {
      left = speeds[i];
      right = speeds[i];
      ++i;
      while (i < speeds.size() && speeds[i] == right+1) {
        ++i; ++right;
      }

      if (!speeds_stream.str().empty()) speeds_stream << ", ";
      speeds_stream << left;
      if (left != right) {
        speeds_stream << "-" << right;
      }
    }

    if (speeds.empty()) speeds_stream << "No acceptable speeds.";

    cout << "Case " << c++ << ": " << speeds_stream.str() << '\n';

    cin.ignore(10000, '\n');
    cin >> n;
  }
}
