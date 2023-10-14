/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "MyObject.h"
#include "main.hpp"

#include "MyObject.h"

std::string value = "Hello World!";
std::string key = "key";

int main(int argc, char **argv) {
    // Create an instance of MyObject using the static function
    MyObjectPtr obj = MyObject::createInstance();
    
    // Just to verify it's working
    std::cout << "Successfully created MyObject instance!" << std::endl;

    obj->print();
    obj->set(value, key);
    std::cout << "Set value: " << obj->get(key) << std::endl;
    obj->print();
    obj->get("key");
    obj->print();
    obj->reset();
    obj->print();
    obj->get("key");
    obj->print();

    // Call destructor
    obj.reset();


    return 0;
}



