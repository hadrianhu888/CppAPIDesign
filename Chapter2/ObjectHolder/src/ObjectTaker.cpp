/**
 * @file ObjectTaker.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ObjectTaker.h"
#include "ObjectHolder.h"
#include "Object.h"

extern ObjectHolder *holder;
extern Object *object;

ObjectTaker::ObjectTaker() : m_object(nullptr) {}

ObjectTaker::~ObjectTaker() {}

void ObjectTaker::setObject(Object *object) {
    m_object = object;
}

Object *ObjectTaker::getObject() {
    return m_object;
}

void ObjectTaker::printObject() const {
    if (m_object) {
        m_object->print();
    } else {
        std::cout << "No object set." << std::endl;
    }
}

void ObjectTaker::print() const {
    std::cout << "ObjectTaker: ";
    printObject();
}

void ObjectTaker::print(std::ostream &os) const {
    os << "ObjectTaker: ";
    printObject(os);
}

void ObjectTaker::printObject(std::ostream &os) const {
    if (m_object) {
        m_object->printObject();
    } else {
        os << "No object set." << std::endl;
    }
}