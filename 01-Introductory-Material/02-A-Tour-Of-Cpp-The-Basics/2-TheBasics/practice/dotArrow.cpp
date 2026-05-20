#include <iostream>

using namespace std;

struct Vector {
  int sz;
};

void f(Vector v, Vector &rv, Vector *pv) {
  cout << "Access through object      : " << v.sz << endl;

  cout << "Access through reference   : " << rv.sz << endl;

  cout << "Access through pointer     : " << pv->sz
       << endl; // -> singkatan dari (∗pv).sz
}

int main() {
  Vector my_vector;

  my_vector.sz = 10;

  f(my_vector, my_vector, &my_vector);

  return 0;
}
