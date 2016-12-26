#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class A {

  private:
    T x;

  public:
    A() {
      cout << "Base class no arg ctor." << endl;
    }
    A(T y) {
      cout << "Base class with arg ctor." << endl;
      x = y;
    }
    virtual void do_something() {
      cout << "Parent class." << endl;
      cout << x << endl;
    }
};

template <typename T>
class B : public A<T> {
  public:
    B() {
      cout << "Sub class no arg ctor." << endl;
    }
    B(int x) {
      cout << "Sub class with arg ctor." << endl;
      cout << x << endl;
    }
    void do_something() {
      cout << "Sub class" << endl;
    }
};

class C {};

template <typename T>
void tfunc(T a, T b) {
  cout << a << b << endl;
}

enum class WeekDay : char {
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};

WeekDay today = WeekDay::Sunday;

int main() {
  A<int> a(5);
  a.do_something();

  C* c = new C;
  C* cc = new C();

  B<char> b(3);
  tfunc<int>(5, 'a');


  return 0;
}
