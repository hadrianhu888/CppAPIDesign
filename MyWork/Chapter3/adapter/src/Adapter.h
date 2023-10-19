/**
 * @file Adapter.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ADAPTER_H
#define ADAPTER_H

#include "singleton.h"
#include <iostream>
#include <memory>

class Adapter {
public:
  Adapter();
  void print();
  // delete copy constructor and assignment operator
  Adapter(const Adapter &);
  Adapter &operator=(const Adapter &);
  Adapter &operator=(Adapter &&);
  ~Adapter();
  Adapter getInstance();
  Adapter getInstance(std::string str);
  Adapter getInstance(int num);

private:
  Singleton *m_pSingleton;
  std::mutex m_mutex;
  std::string m_str;
};

#endif /* ADAPTER_H */