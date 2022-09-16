#ifndef _isubject_
#define _isubject_

#include "IObserver.h"

class ISubject {
public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void notifyObservers(Media* pMedia) = 0;
};

#endif