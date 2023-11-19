/**
 * @file CppAdapter.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CPP_ADAPTER_H
#define CPP_ADAPTER_H

#include <iostream>
#include <string>
#include <vector>

class CppAdapter {
public:
  CppAdapter();
  ~CppAdapter();
  void DoSomething(void);
  void DoSomethingElse(void);
  void DoSomethingMore(void);

private:
  std::string m_str;
  

#endif // CPP_ADAPTER_H