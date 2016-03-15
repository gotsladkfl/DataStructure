#pragma once

#include <iostream>
#include <functional>
#include "node.h"


using namespace std;




/*      

        �Էµ� ũ�⿡ ���� Ʈ���� �����Ͽ� 

        Ž���� �����ϰ� ���� ���� Ž�� Ʈ��  

*/


template <typename T>
class BinarySearchTree 
{

 private:

  Node<T>* root;             
  bool check_endl;
  bool check_space;

  bool internal_remove(Node<T>*& current, T value, function<int(T&, T&)>& comp);
  bool internal_insert(Node<T>*& current, T value, function<int(T&, T&)>& f);

  Node<T>*& find_left_most_child(Node<T>*& current);
  void replace_node(Node<T>*& replaced, Node<T>*& newone);

  void print_Tree(Node<T> *node, int depth );
 public:

  BinarySearchTree<T>();
  ~BinarySearchTree<T>();

  bool remove(T value, function<int(T&, T&)>& comp);
 
  bool insert(T value, function<int(T&, T&)>& f);
 
  void print_Tree();
};
