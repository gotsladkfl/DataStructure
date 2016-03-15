#pragma once

template <typename T>
class BinarySearchTree;


/*       값과 좌우 노드를 갖는   트리의 노드         */


template <typename T>
class Node {

  friend class BinarySearchTree<T>;
  
private:
  T data;
  Node* left;
  Node* right;

public:
  Node() {
    left = nullptr;
    right = nullptr;
  }

  Node(T t) {
    data = t;
    left = nullptr;
    right = nullptr;
  }

  ~Node() {
  }
};