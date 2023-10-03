// Simplified example
#include "coordinates.h"

void *instantiateModel() {
  Coordinates *coordinates = new Coordinates(0.0, 0.0);
}

void freeModel(void *instance) {
  delete (Coordinates<double> *)instance; // Replace with your actual destructor
}

void setX(void *instance, double value) {
  ((Coordinates<double> *)instance)
      ->setX(value); // Replace with your actual function to set X
}

void setY(void *instance, double value) {
  ((Coordinates<double> *)instance)
      ->setY(value); // Replace with your actual function to set Y
}

// Additional FMI-compliant C API functions
