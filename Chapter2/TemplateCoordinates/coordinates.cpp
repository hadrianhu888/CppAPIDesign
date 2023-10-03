/**
 * @file coordinates.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "coordinates.h"

// Explicit instantiation of the Coordinates template for certain types
class MyClass {};
template class Coordinates<int>;
template class Coordinates<float>;
template class Coordinates<double>;
template class Coordinates<std::string>;
template class Coordinates<MyClass>;
template class Coordinates<MyClass *>;
template class Coordinates<MyClass &>;
template class Coordinates<MyClass const *>;
template class Coordinates<MyClass const &>;
