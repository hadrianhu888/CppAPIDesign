/**
 * @file ObjectHolder.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ObjectHolder.h"
#include "Object.h"

extern ObjectHolder *holder;
extern Object *object;

ObjectHolder::ObjectHolder() : parent(nullptr), child(nullptr) {std::cout << "ObjectHolder constructor called" << std::endl;}

ObjectHolder::~ObjectHolder() {std::cout << "ObjectHolder destructor called" << std::endl;}

void ObjectHolder::setObjectName(std::string name) { m_name = name; }

std::string ObjectHolder::getObjectName() { return m_name; }

void ObjectHolder::setParent(Object *parent) {
    m_parent = std::shared_ptr<Object>(parent);
}

Object ObjectHolder::getParent() { return *m_parent; }

void ObjectHolder::addChild(std::shared_ptr<Object> child) {
    m_children.push_back(child);
}

Object ObjectHolder::getChildren() { return *m_children.back(); }

void ObjectHolder::printChildren() const { printChildren(std::cout); }

void ObjectHolder::printObject() const { printObject(std::cout); }

void ObjectHolder::print() const { print(std::cout); }

void ObjectHolder::print(std::ostream &os) const {
    printObject(os);
    os << std::endl;
    printChildren(os);
}

void ObjectHolder::printChildren(std::ostream &os) const {
    for (auto child : m_children) {
        child->printChildren();
    }
}

void ObjectHolder::printObject(std::ostream &os) const {
    os << "ObjectHolder: " << m_name;
}
