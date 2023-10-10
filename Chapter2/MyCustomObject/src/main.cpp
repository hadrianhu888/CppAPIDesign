/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "MyCustomObject.h"

int main(int argc, char **argv) {
    my_custom_object::MyCustomObject obj;
    obj.setName("John");
    obj.setAge(25);
    obj.setHeight(1.75);
    obj.setWeight(80.0);
    obj.setGender("Male");
    obj.setHairColor("Brown");
    obj.setMap({{"key1", "value1"}, {"key2", "value2"}});
    obj.print();
    return 0;
}
