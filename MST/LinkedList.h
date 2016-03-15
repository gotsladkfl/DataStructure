#pragma once

#include "LinkedNode.h"

template <class T>
class LinkedList
{
	friend class LinkedDigraph ;
	friend class LinkedGraph ;
	friend class LinkedWGraph ;
private :

	LinkedNode<T>* node ;
public :
	LinkedList() ;
};

template <class T>
LinkedList<T>::LinkedList()
{
	node = new LinkedNode<T>();
}
