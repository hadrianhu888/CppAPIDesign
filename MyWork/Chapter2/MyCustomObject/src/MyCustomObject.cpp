#include "MyCustomObject.h"

namespace my_custom_object {

// Constructor
MyCustomObject::MyCustomObject()
    : m_name(""), m_age(0), m_height(0.0), m_weight(0.0), m_gender(""),
      m_hair_color("") {}

// Destructor
MyCustomObject::~MyCustomObject() {}

// Public member functions
void MyCustomObject::print() {
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
    std::cout << "Height: " << m_height << std::endl;
    std::cout << "Weight: " << m_weight << std::endl;
    std::cout << "Gender: " << m_gender << std::endl;
    std::cout << "Hair Color: " << m_hair_color << std::endl;
}

void MyCustomObject::setName(std::string name) {
    m_name = name;
}

void MyCustomObject::setAge(int age) {
    m_age = age;
}

void MyCustomObject::setHeight(double height) {
    m_height = height;
}

void MyCustomObject::setWeight(double weight) {
    m_weight = weight;
}

void MyCustomObject::setGender(std::string gender) {
    m_gender = gender;
}

void MyCustomObject::setHairColor(std::string hair_color) {
    m_hair_color = hair_color;
}

void MyCustomObject::setMap(std::map<std::string, std::string> map) {
    m_map = map;
}

void MyCustomObject::setMapIterator(std::map<std::string, std::string>::iterator map_iterator) {
    m_map_iterator = map_iterator;
}

} 