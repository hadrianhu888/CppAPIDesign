/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "main.h"
#include <iostream>
#include <memory>

int main(int argc, char **argv)
{
  // create Object, ObjectHolder and ObjectTaker
  Object *object = new Object();
  ObjectHolder *holder = new ObjectHolder();
  ObjectTaker *taker = new ObjectTaker();

  // set object name
  object->setObjectName("Object");
  holder->setObjectName("ObjectHolder");
  taker->setObjectName("ObjectTaker");

  // set parent
  holder->setParent(object);

  // add child
  holder->addChild(std::shared_ptr<Object>(object));

  // set object
  taker->setObject(object);

  // print
  object->print();
  holder->print();
  taker->print();

  // delete
  delete object;
  delete holder;
  delete taker;

  return 0;
}

