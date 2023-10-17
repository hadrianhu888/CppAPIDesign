#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>
#include <mutex>
#include <string>

class Singleton {
public:
  static Singleton &getInstance();
  void print();
  // delete copy constructor and assignment operator
  Singleton(const Singleton &);
  Singleton &operator=(const Singleton &);
  Singleton &operator=(Singleton &&);
  ~Singleton();

private:
  Singleton() {}
};

#endif // SINGLETON_H
