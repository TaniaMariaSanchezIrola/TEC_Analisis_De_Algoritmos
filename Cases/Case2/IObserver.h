#ifndef _iobserver_
#define _iobserver_

#include <iostream>
#include <string>

class IObserver {
public:
    virtual ~IObserver(){};
    virtual void Update(const int pId) = 0;
};

#endif