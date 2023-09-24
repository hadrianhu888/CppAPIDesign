/**
 * @file extern_test.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CHAPTER2_EXTERN_TEST_HPP_
#define CHAPTER2_EXTERN_TEST_HPP_

extern int i;

#include <iostream>
#include <string>
using namespace std;

class MyClass {};
class MyClass1 {
public:
    MyClass1() { std::cout << "MyClass constructor" << std::endl; }
    ~MyClass1() { std::cout << "MyClass destructor" << std::endl; }
};

void myFunction();

#endif  // CHAPTER2_EXTERN_TEST_HPP_