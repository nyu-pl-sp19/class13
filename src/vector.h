#pragma once
#include <cstring>

class ArrayIndexOutOfBoundsException {};

template<typename T>
class Vector {
  size_t size;
  T* data; // pointer to heap-allocated array
public:
  // Standard constructor
  Vector(size_t _size)
    : size(_size), data(new T[_size]) {
  }

  // Copy constructor
  Vector(const Vector<T>& other)
    : size(other.size), data(new T[other.size]) {
    std::memcpy(data, other.data, size * sizeof(T));
  }

  // Destructor
  ~Vector() {
    delete[] data;
  }

  // Resizing
  void resize(size_t new_size) {
    if (size == new_size) return;
    delete[] data;
    size = new_size;
    data = new T[size];    
  }
  
  // Assignment operator
  Vector<T>& operator=(const Vector<T>& right) {
    if (right.data != data) {
      resize(right.size);
      memcpy(data, right.data, size * sizeof(T));
    }
    return *this;
  }
  
  // Array access
  T& operator[](int32_t index) {
    if (0 > index || index >= size) {
      throw ArrayIndexOutOfBoundsException();
    }
    return data[index];
  }

  const T& operator[](int32_t index) const {
    if (0 > index || index >= size) {
      throw ArrayIndexOutOfBoundsException();
    }
    return data[index];
  }
  
};
