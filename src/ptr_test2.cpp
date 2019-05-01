#include <iostream>
#include "ptr.h"
#include "vector.h"

struct A;

struct B {
  Ptr<A> a;
  B(Ptr<A>& _a) : a(_a) { TRACE("B(Ptr<A>&)"); }
  B(A* _a) : a(_a) { TRACE("B(A*)"); }
  ~B() { TRACE("~B"); }
};

struct A {
  Ptr<B> b;
  A(Ptr<B>& _b) : b(_b) { TRACE("A(Ptr<B>&)");}
  ~A() { TRACE("~A"); }
};

int main(void) {
  Vector<int> v(10);
  v.resize(20);
  v[0] = 1;
  Vector<int> w = v;
  //w[0] = 0;
  
  std::cout << v[0] << std::endl;
  //std::cout << w[0] << std::endl;

  Ptr<B> pn = 0;

  Ptr<B> pb = new B(0);

  Ptr<A> pa = new A(pb);

  pb->a = pa;

  pa->b = pn;

  return 0;
}
