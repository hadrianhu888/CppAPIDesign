#include "./../source/MyObject.h"
#include <cassert>

void test_instance_creation() {
    MyObjectPtr obj = MyObject::createInstance();
    // Ensure the object is successfully created.
    assert(obj != nullptr);
}

void test_destruction() {
    MyObjectPtr obj = MyObject::createInstance();
    // Ensure the object is successfully created.
    assert(obj != nullptr);
    // Delete the object
    obj.reset(); 
    assert(!obj);

    // Ensure the object is successfully deleted.
    assert(obj == nullptr);
}

void test_set_get_reset() {
    MyObjectPtr obj = MyObject::createInstance();
    // Ensure the object is successfully created.
    assert(obj != nullptr);
    // Set the value of the object
    obj->set("Hello World!", "key");
    // Get the value of the object
    std::string value = obj->get("key");
    // Ensure the value is correct
    assert(value == "Hello World!");
    // Reset the value of the object
    obj->reset();
    // Get the value of the object
    value = obj->get("key");
    // Ensure the value is correct
    assert(value == "");
}

void test_get_non_existent_key() {
    MyObjectPtr obj = MyObject::createInstance();
    // Ensure the object is successfully created.
    assert(obj != nullptr);
    // Get the value of the object
    std::string value = obj->get("key");
    // Ensure the value is correct
    assert(value == "");
}

int main() {
    test_instance_creation();
    test_destruction();
    test_set_get_reset();
    test_get_non_existent_key();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
