/*
ID: fgasper2
LANG: C++
TASK: test
*/

#include <fstream>

using namespace std;

int main() {
  ifstream input_file_stream("test.in");
  ofstream output_file_stream("test.out");

  int a, b;
  input_file_stream >> a >> b;
  output_file_stream << a + b << endl;

  return 0;
}
