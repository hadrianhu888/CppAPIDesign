/**
 * @file Object.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Object.h"

extern Object *object;

Object::Object() : parent(nullptr), child(nullptr) {}

Object::~Object() {}

void Object::setObjectName(std::string name) {
    this->name = name;
}

std::string Object::getObjectName() {
    return name;
}

void Object::setParent(Object *parent) {
    this->parent = parent;
}

Object Object::getParent() {
    return *parent;
}

void Object::addChild(std::shared_ptr<Object> child) {
    m_children.push_back(child);
}

Object Object::getChildren() {
    return *child;
}

void Object::printChildren() {
    printChildren(std::cout);
}

void Object::printObject() {
    printObject(std::cout);
}

void Object::print() {
    print(std::cout);
}

void Object::print(std::ostream &os) const {
    printObject(os);
    os << std::endl;
    printChildren(os);
}

void Object::printChildren(std::ostream &os) const {
    for (const auto &child : m_children) {
        child->print(os);
    }
}

void Object::printObject(std::ostream &os) const {
    os << "Object: " << m_name;
    if (m_parent) {
        os << " (child of " << m_parent->m_name << ")";
    }
}