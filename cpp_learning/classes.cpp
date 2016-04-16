#include<iostream>
#include<vector>

using namespace std;

class A {
  public:
    int an_int;
    int* arr;

    A(int a) : an_int(a) {
      arr = new int[a];
    };
    A() : an_int(0) {};

    virtual void do_something() {
      cout << "Parent class." << endl;
      cout << an_int << endl;
    }
    void set_int(int i) {
      an_int = i;
    }

    ~A() {
      delete[] arr;
    }

};

class B : public A {

  friend void friendly_function(B& obj);

  public:
    B(int a) : priv_int(4), prot_int(9) {};

    void do_something() {
      cout << "Sub class" << endl;
      cout << an_int << endl;
    }

  protected:
    int prot_int;

  private:
    int priv_int;
};

void friendly_function(B& obj) {
  cout << obj.priv_int << endl;
  cout << obj.prot_int << endl;
};

int main() {
  /* B b(5); */
  /* A& a = b; */
  /* a.set_int(3); */
  /* a.do_something(); */
  /* b.do_something(); */
  /* friendly_function(b); */

  /* A c(8); */
  /* c.do_something(); */


  return 0;
}
