#pragma once

template <typename T>
class BinarySearchTree;


/*       ���� �¿� ��带 ����   Ʈ���� ���         */


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