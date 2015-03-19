#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  int test_cases;
  cin >> test_cases;
  for (int t = 1; t<=test_cases; ++t) {
    string program;
    cin >> program;

    unsigned char led_memory[100];
    for (int i = 0; i < 100; ++i) {led_memory[i] = 0;}
    short led_pointer = 0;
    for (int i = 0; i < program.length(); ++i) {
      if (program[i] == '>') {
        led_pointer = (led_pointer+1) % 100;
      }
      if (program[i] == '<') {
        led_pointer = (led_pointer+99) % 100;
      }
      if (program[i] == '+') {
        ++led_memory[led_pointer];
      }
      if (program[i] == '-') {
        --led_memory[led_pointer];
      }
    }

    cout << "Case " << dec << t << ":";
    for (int i = 0; i < 100; ++i) {
      cout << " " << setfill('0') << setw(2) << uppercase << hex << (int)led_memory[i];
    }
    cout << endl;
  }

  return 0;

}
