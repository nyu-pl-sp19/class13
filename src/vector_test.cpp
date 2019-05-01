#include <iostream>
#include "vector.h"

int main(void) {
  Vector<int> v(10);

  v.resize(20);

  v[0] = 1;

  Vector<int> w = v;

  w[0] = 0;
  
  std::cout << v[0] << std::endl;
  std::cout << w[0] << std::endl;
}
