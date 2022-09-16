#ifndef _node_
#define _node_

#include <iostream>

using namespace std;

template <class T>
class Node{
	private:
		T data;
		Node<T>* next;
		
	public:
		Node(T pData){
			data = pData;
			next = NULL;
		}
		
		T getData(){
			return data;
		}
		
		Node<T>* getNext(){
			return next; 
		}
		
		void setNext(Node<T>* pNext){
			next = pNext;
		}
};

#endif
