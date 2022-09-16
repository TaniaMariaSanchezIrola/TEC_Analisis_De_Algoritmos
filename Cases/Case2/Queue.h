#ifndef _queue_
#define _queue_
#include "LinkedList.h"


template <class T>
class Queue : public LinkedList<T>{
    
  public:
    void enqueue(T pData){
    	LinkedList<T>::addLast(pData);
	}
	
	T dequeue(){
		T removedData = LinkedList<T>::removeFirst();
		return removedData;
	}
};

#endif
