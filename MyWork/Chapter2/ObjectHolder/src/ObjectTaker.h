/**
 * @file ObjectTaker.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Object.h"

#ifndef OBJECTTAKER_H_
#define OBJECTTAKER_H_

class ObjectTaker : public Object {
private:
  Object *m_object;

public:
  ObjectTaker();
  virtual ~ObjectTaker();

  void setObject(Object *object);
  Object *getObject();

  void printObject() const;
  void print() const;

protected:
  virtual void print(std::ostream &os) const;
  virtual void printObject(std::ostream &os) const;
};


#endif /* OBJECTTAKER_H_ */
