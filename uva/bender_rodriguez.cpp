#include <iostream>
#include <string>

using namespace std;

void change_sign(string &direction)
{
  if (direction[0] == '+') {
    direction[0] = '-';
  } else {
    direction[0] = '+';
  }
}

int main()
{
  int wire_length;
  cin >> wire_length;
  while (wire_length > 0) {
    string bend_direction;
    string last_segment_direction = "+x";
    for (int i = 0; i < wire_length-1; ++i) {
      cin >> bend_direction;
      if (bend_direction != "No") {
        // case last x
        if (last_segment_direction[1] == 'x') {
          if (last_segment_direction[0] == '-') {
            change_sign(bend_direction);
          }
          last_segment_direction = bend_direction;
        // case last y
        } else if (last_segment_direction[1] == 'y' && bend_direction[1] == 'y') {
          // case +
          if (last_segment_direction[0] == '+') {
            if (bend_direction[0] == '+') {
              last_segment_direction = "-x";
            } else {
              last_segment_direction = "+x";
            }
          // case -
          } else {
            last_segment_direction[0] = bend_direction[0];
            last_segment_direction[1] = 'x';
          }
        // case last z
        } else if (last_segment_direction[1] == 'z' && bend_direction[1] == 'z') {
          if (last_segment_direction[0] == '+') {
            if (bend_direction[0] == '+') {
              last_segment_direction = "-x";
            } else {
              last_segment_direction = "+x";
            }
          } else {
            last_segment_direction[0] = bend_direction[0];
            last_segment_direction[1] = 'x';
          }
        }
      }
    }

    cout << last_segment_direction << endl;

    cin >> wire_length;
  }

  return 0;
}
