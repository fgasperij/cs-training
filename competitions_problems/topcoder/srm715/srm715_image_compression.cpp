#include <vector>
#include <string>

using namespace std;

class ImageCompression {
public:
  string isPossible(vector<string> image, int k) {
    int b_rows = image.size()/k;
    int b_cols = image[0].size()/k;
    for (int br = 0; br < b_rows; ++br) {
      for (int bc = 0; bc < b_cols; ++bc) {

        char block_value = image[br*k][bc*k];
        for (int i = 0; i < k; ++i) {
          for (int j = 0; j < k; ++j) {
            if (image[br*k+i][bc*k+j] != block_value) {
              return string("Impossible");
            }
          }
        }

      }
    }

    return string("Possible");
  }
};