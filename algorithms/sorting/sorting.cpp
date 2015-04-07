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

vector<int> generate_random_vector(int max_size) {
  int size = get_random(1, max_size);
  vector<int> A(size);
  for (int i = 0; i<size; ++i) {
    A[i] = get_random(0, 1000);
  }
  return A;
}

void merge(vector<int> &A, vector<int> &scratch, int left, int middle, int right) {
  int first_i = left, second_i = middle, merged_i = left;
  while (first_i < middle || second_i < right) {
    if (first_i >= middle) {
      scratch[merged_i] = A[second_i];
      ++second_i;
      ++merged_i;
      continue;
    }
    if (second_i >= right) {
      scratch[merged_i] = A[first_i];
      ++first_i;
      ++merged_i;
      continue;
    }
    if (A[second_i] < A[first_i]) {
      scratch[merged_i] = A[second_i];
      ++second_i;
    } else {
      scratch[merged_i] = A[first_i];
      ++first_i;
    }
    ++merged_i;
  }

  return;
}

void merge_with_copy_back(vector<int> &A, vector<int> &scratch, int left, int middle, int right) {
  int first_i = left, second_i = middle, merged_i = left;
  while (first_i < middle || second_i < right) {
    if (first_i >= middle) {
      scratch[merged_i] = A[second_i];
      ++second_i;
      ++merged_i;
      continue;
    }
    if (second_i >= right) {
      scratch[merged_i] = A[first_i];
      ++first_i;
      ++merged_i;
      continue;
    }
    if (A[second_i] < A[first_i]) {
      scratch[merged_i] = A[second_i];
      ++second_i;
    } else {
      scratch[merged_i] = A[first_i];
      ++first_i;
    }
    ++merged_i;
  }

  for (int i = left; i < right; ++i) {
    A[i] = scratch[i];
  }

  return;
}

void interval_insertion_sort(vector<int> &A, int left, int right) {
  int j;
  for (int i = left+1; i < right; ++i) {
    j = i;
    while (j > left && A[j] < A[j-1]) {
      swap(A[j], A[j-1]);
      --j;
    }
  }
}

void insertion_sort(vector<int> &A) {
  interval_insertion_sort(A, 0, A.size());
}

void merge_sort_to_scratch(vector<int> &A, int left, int right, vector<int> &scratch);

void merge_sort_to_A(vector<int> &A, int left, int right, vector<int> &scratch) {
  if (right-left <= 6) {
    interval_insertion_sort(A, left, right);
    return;
  }

  int middle = left + (right-left)/2;
  merge_sort_to_scratch(A, left, middle, scratch);
  merge_sort_to_scratch(A, middle, right, scratch);

  if (A[middle-1] > A[middle]) {
    merge(scratch, A, left, middle, right);
  }

  return;
}

void merge_sort_to_scratch(vector<int> &A, int left, int right, vector<int> &scratch) {
  if (right-left <= 6) {
    interval_insertion_sort(A, left, right);
    for (int i = left; i < right; ++i) {
      scratch[i] = A[i];
    }
    return;
  }

  int middle = left + (right-left)/2;
  merge_sort_to_A(A, left, middle, scratch);
  merge_sort_to_A(A, middle, right, scratch);

  if (A[middle-1] > A[middle]) {
    merge(A, scratch, left, middle, right);
  }

  return;
}

void merge_sort(vector<int> &A, int left, int right, vector<int> &scratch) {
  if (right-left <= 6) {
    interval_insertion_sort(A, left, right);
    return;
  }

  int middle = left + (right-left)/2;
  merge_sort(A, left, middle, scratch);
  merge_sort(A, middle, right, scratch);

  if (A[middle-1] > A[middle]) {
    merge_with_copy_back(A, scratch, left, middle, right);
  }

  return;
}

int main() {
  srand(time(NULL));

  // merge sort
  cout << "Merge sort with copy back\n";
  vector<int> A = generate_random_vector(100);
  vector<int> scratch(A.size());
  print_vector(A);
  merge_sort(A, 0, A.size(), scratch);
  print_vector(A);
  cout << (is_sorted(A) ? "SUCCESSFULL!" : "WRONG!") << endl;

  // merge sort
  cout << "Merge sort without copy back\n";
  vector<int> C = generate_random_vector(100);
  vector<int> scratch2(C.size());
  print_vector(C);
  merge_sort_to_A(C, 0, C.size(), scratch2);
  print_vector(C);
  cout << (is_sorted(C) ? "SUCCESSFULL!" : "WRONG!") << endl;

  // insertion sort
  cout << "Insertion sort\n";
  vector<int> B = generate_random_vector(100);
  print_vector(B);
  insertion_sort(B);
  print_vector(B);
  cout << (is_sorted(B) ? "SUCCESSFULL!" : "WRONG!") << endl;


  return 0;
}
