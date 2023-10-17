#include "singleton.h"

static Singleton *instance = nullptr;

Singleton &Singleton::getInstance() {
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return *instance; // fixed: dereference the pointer to return a reference to
                    // the Singleton object
}

Singleton::Singleton(const Singleton &) {}

Singleton &Singleton::operator=(const Singleton &) { return *this; }

Singleton::~Singleton() {}

void Singleton::print() { std::cout << "Singleton::print()" << std::endl; }

Singleton &Singleton::operator=(Singleton &&) { return *this; }

// Path: MyWork/Chapter3/singleton/src/main.cpp
