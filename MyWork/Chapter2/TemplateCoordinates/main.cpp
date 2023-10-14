#include "coordinates.h"

int main() {
  Coordinates<int> intCoord(3, 4);
  intCoord.print(); // Output should be "x: 3, y: 4"

  Coordinates<double> doubleCoord(3.0, 4.0);
  doubleCoord.print(); // Output should be "x: 3, y: 4"

  return 0;
}
