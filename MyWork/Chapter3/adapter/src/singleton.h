#ifndef B510245A_5754_4891_B1D4_CC951AE737AA
#define B510245A_5754_4891_B1D4_CC951AE737AA
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
  static Singleton getInstance(std::string str);
  static Singleton getInstance(int num);

private:
  Singleton() {}
};

#endif // SINGLETON_H

#endif /* B510245A_5754_4891_B1D4_CC951AE737AA */
