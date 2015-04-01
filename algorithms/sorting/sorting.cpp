#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_vector(const vector<int> &A) {
  cout << "A: ";
  for (int i = 0; i < A.size(); ++i) {
    cout << A[i] << " ";
  }
  cout << endl;
}

bool is_sorted(const vector<int> &A) {
  for (int i = 1; i < A.size(); ++i) {
    if (A[i] < A[i-1]) {
      return false;
    }
  }

  return true;
}

int get_random(int lower, int upper) {
  long range = (upper-lower)+1;
  long rand_res = rand();
  int random = lower + int(range*rand_res / (RAND_MAX + 1.0));
  return random;
}

vector<int> generate_random_vector() {
  int size = get_random(1, 30);
  vector<int> A(size);
  for (int i = 0; i<size; ++i) {
    A[i] = get_random(0, 1000);
  }
  return A;
}

vector<int> merge(const vector<int> &first, const vector<int> &second) {
  vector<int> merged(first.size() + second.size());
  int first_i = 0, second_i = 0, merged_i = 0;
  while (first_i < first.size() || second_i < second.size()) {
    if (first_i >= first.size()) {
      merged[merged_i] = second[second_i];
      ++second_i;
      ++merged_i;
      continue;
    }
    if (second_i >= second.size()) {
      merged[merged_i] = first[first_i];
      ++first_i;
      ++merged_i;
      continue;
    }
    if (second[second_i] < first[first_i]) {
      merged[merged_i] = second[second_i];
      ++second_i;
    } else {
      merged[merged_i] = first[first_i];
      ++first_i;
    }
    ++merged_i;
  }

  return merged;
}

vector<int> merge_sort(const vector<int> &A) {
  if (A.size() == 1) {
    return vector<int> (A);
  }
  vector<int> first = vector<int> (A.begin(), (A.begin()+(A.size()/2)));
  vector<int> second = vector<int> ((A.begin()+(A.size()/2)), A.end());

  first = merge_sort(first);
  second = merge_sort(second);

  vector<int> result = merge(first, second);

  return result;
}

int main() {
  srand(time(NULL));

  vector<int> A = generate_random_vector();
  vector<int> A_sorted = merge_sort(A);

  print_vector(A);
  print_vector(A_sorted);

  cout << (is_sorted(A_sorted) ? "SUCCESSFULL!" : "WRONG!") << endl;

  return 0;
}
