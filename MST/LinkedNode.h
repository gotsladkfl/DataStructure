#pragma once

template <class T>
class LinkedList ;

template <class T>
class LinkedNode
{
	friend class LinkedList<T> ;
	friend class LinkedDigraph ;
	friend class LinkedGraph ;

private :

	LinkedNode<T>* link ;
	T data ;

public :

	LinkedNode() ;
	LinkedNode( T data, LinkedNode<T>* link ) ;

};

template <class T>
LinkedNode<T>::LinkedNode() 
{
	link = 0 ;
}
template <class T>
LinkedNode<T>::LinkedNode( T data, LinkedNode<T>* link ) 
{
	this->data = data;
	this->link = link;
}