/**
 * @file ObjectHolder.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef OBJECTHOLDER_H_
#define OBJECTHOLDER_H_

#include "Object.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ObjectHolder : public Object {
private:
  std::string m_name;
  std::shared_ptr<Object> m_parent;
  std::vector<std::shared_ptr<Object>> m_children;

protected:
  virtual void print(std::ostream &os) const;
  virtual void printChildren(std::ostream &os) const;
  virtual void printObject(std::ostream &os) const;

public:
  Object *parent;
  std::string name;
  Object *child;
  ObjectHolder();
  virtual ~ObjectHolder();

  void setObjectName(std::string name);
  std::string getObjectName();

  void setParent(Object *parent);
  Object getParent();

  void addChild(std::shared_ptr<Object> child);
  Object getChildren();

  void printChildren() const;
  void printObject() const;
  void print() const;
};

#endif /* OBJECTHOLDER_H_ */