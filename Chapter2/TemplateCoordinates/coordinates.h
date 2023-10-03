#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
#include <string.h>

template <typename T> class Coordinates {
private:
  T x;
  T y;

public:
  Coordinates(T x, T y);
  void print();
};

#include "coordinates.tpp"

#endif // COORDINATES_H
