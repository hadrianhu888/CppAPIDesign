template <typename T>
Coordinates<T>::Coordinates(T x, T y) {
  this->x = x;
  this->y = y;
}

template <typename T>
void Coordinates<T>::print() {
  std::cout << "x: " << x << ", y: " << y << std::endl;
}
