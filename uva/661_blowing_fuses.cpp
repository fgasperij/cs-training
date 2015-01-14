#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Device {
  bool is_on;
  int consumption;
};

int main()
{
  int i_devices, i_operations, fuse_capacity, sequence = 1;
  cin >> i_devices;
  while (i_devices) {
    cin >> i_operations >> fuse_capacity;
    vector<Device> devices (i_devices+1);

    int consumption;
    for (int i = 1; i <= i_devices; ++i) {
      devices[i].is_on = false;
      cin >> consumption;
      devices[i].consumption = consumption;
    }

    bool blown = false;
    int device_idx;
    int fuse = 0, max_fuse = 0;
    for (int op = 0; op < i_operations; ++op) {
      cin >> device_idx;
      if (devices[device_idx].is_on) {
        fuse -= devices[device_idx].consumption;
      } else {
        fuse += devices[device_idx].consumption;
        max_fuse = max(max_fuse, fuse);
        if (fuse > fuse_capacity) {
          blown = true;
        }
      }
      devices[device_idx].is_on = !devices[device_idx].is_on;
    }

    cout << "Sequence " << sequence << endl;
    if (blown) {
      cout << "Fuse was blown." << endl;
    } else {
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << max_fuse << " amperes." << endl;
    }
    cout << endl;

    ++sequence;
    cin >> i_devices;
  }

  return 0;
}
