#ifndef _stack_
#define _stack_
#include "LinkedList.h"


template <class T>
class Stack : public LinkedList<T>{
  
  public: 	
	  
    void push(T pData){
    	LinkedList<T>::addFirst(pData);    	
	}
	
	T pop(){
		T removedData = LinkedList<T>::removeFirst();
		return removedData;
	}
};

#endif
