/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "main.h"
#include "singleton.h"
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

string str = "Hello World";
int num = 10;

int main(int argc, char **argv) {
  Singleton &s1 = Singleton::getInstance();
  s1.print();
  Singleton &s2 = Singleton::getInstance();
  s2.print();
  return 0;
}
