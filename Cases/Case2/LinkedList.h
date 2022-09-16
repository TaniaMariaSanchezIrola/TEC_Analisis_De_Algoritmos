#ifndef _linkedlist_
#define _linkedlist_
#include "Node.h"

template <class T>
class LinkedList {
    //Attributes
    Node<T>* first, * last;
    
  public:
    //Methods
    LinkedList(){
    	first = NULL;
    	last = NULL;
	}
	
	void addLast(T pData){
		Node<T>* newNode = new Node<T>(pData);	//creates new node
		if(first == NULL){	//empty list
			first = newNode;
			last = newNode;
		}
		else{
			last->setNext(newNode);
			last = newNode;
		}
	}
	
	void addFirst(T pData){
		Node<T>* newNode = new Node<T>(pData);	//creates new node
		if(first == NULL){	//empty list
			first = newNode;
			last = newNode;
		}
		else{
			newNode->setNext(first);
			first = newNode;
		}
	}
	
	T removeFirst(){
		Node<T>* tmp = first;
		first = first->getNext();
		tmp->setNext(NULL);
		
		return tmp->getData();
	}
	
	Node<T>* getFirst(){
		return first;
	}
	
	Node<T>* getLast(){
		return last;
	}
};

#endif
