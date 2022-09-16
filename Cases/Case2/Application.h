#ifndef _application_
#define _application_

#include <iostream>
#include <list>
#include "ISubject.h"
#include "Media.h"

class Application : public ISubject {
    //Attributes here.

  private:
    std::list<IObserver *> observers;
  public:
    //Methods here.
    Application(std::list<IObserver *> pList){
      this->observers = pList;
    }

    void select(Media *pMedia){
      notifyObservers(pMedia);
    }

    void Attach(IObserver *observer) override {
      this->observers.push_back(observer);
    }

    void Detach(IObserver *observer) override {
      this->observers.remove(observer);
    }

    void notifyObservers(Media *pMedia) override {
      for(IObserver* observer : this->observers){
        observer->Update(pMedia->getId());
      }
    }
};

#endif
