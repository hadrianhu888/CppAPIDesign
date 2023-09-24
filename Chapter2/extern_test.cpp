/**
 * @file extern_test.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */


#include <iostream>
#include <string>
#include "extern_test.hpp"

extern int i;
class MyClass;
extern void myFunction();

int i = 0;
void myFunction() {
    std::cout << "i = " << i << std::endl;
    i++;
}
class MyClass1 {
    public:
        MyClass1() { std::cout << "MyClass constructor" << std::endl; }
        ~MyClass1() { std::cout << "MyClass destructor" << std::endl; }
};

int extern_main(int argc, char **argv) {
    MyClass1 myClass;
    myClass.~MyClass1();
    myFunction();
    return 0;
}


