#include "BinarySearchTree.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() 
{
	 root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() 
{
	if(root)
		 delete root;
}

/*    BST ���� ���� ���� �ڽ����� ��ü�Ϸ��� ���� ����° ��� ã��   */
template <typename T>
Node<T>*& BinarySearchTree<T>::find_left_most_child(Node<T>*& current)
{
  while(current->left)
  {
    current = current->left;
  }
  
  return current;
}

/*      ���ο� ��带 ������ ���� ��ü        */

template <typename T>
void BinarySearchTree<T>::replace_node(Node<T>*& replaced, Node<T>*& newone) 
{

  if (replaced == NULL || newone == NULL) 
  {
    return;
  }

  if (replaced->left != NULL && replaced->right != NULL) 
  {
      newone->left = replaced->left;
    if(replaced->right != newone)
      newone->right = replaced->right;
  }
  
  Node<T>* temp = replaced;
  replaced = newone;
  delete temp;
  
  return;
}

/*          �߰�    wrapper method           */
template <typename T>
bool BinarySearchTree<T>::insert(T value, function<int(T&, T&)>& comp) 
{
  return internal_insert(root, value, comp);
}

template <typename T>
bool BinarySearchTree<T>::internal_insert(Node<T>*& current, T value,
                                          function<int(T&, T&)>& comp) 
{
  /*       ������� ������� ���� ���� ��忡�� ũ�� ������ ������ ����..�̷������� ��͸� Ÿ�� ��   */

	/*  ù ����� ���  */
  if (current == NULL) 
  {
    current = new Node<T>(value);
    return true;
  } 
  /*  ���� ���� �� ũ�� �Է� ���� ���ʿ� */
  else if (comp(current->data, value) == -1)  
  {
    return internal_insert(current->left, value, comp);
  }
  else if (comp(current->data, value) == 1) 
  {
    return internal_insert(current->right, value, comp);
  } 

  return false;
}



/*           ���� wrapper method           */
template <typename T>
bool BinarySearchTree<T>::remove(T value, function<int(T&, T&)>& comp)
{
  return internal_remove(root, value, comp);
}

template <typename T>
bool BinarySearchTree<T>::internal_remove(Node<T>*& current, T value,
                                          function<int(T&, T&)>& comp) 
{
	/*    ã�Ҵµ� ���� �ڽ��� 1. ���� �� 2. �ϳ��� ���� �� ( ��,�� ) 3. �Ѵ� ���� ��   */
  if (comp(current->data, value) == 0) 
  {
    if (current->left == NULL && current->right == NULL) 
	{
      // 1. ���� �ڽ��� �ϳ��� ���� ���� �׳� ������Ű�� ��
      delete current;
      current = NULL;
    } 
	else if (current->left != NULL && current->right == NULL) 
	{
      // ���� �ڽ��� �Ѹ� �ִ� ��� ���� �ڽ����� ��ü,
      replace_node(current, current->left);
    }
	else if (current->left == NULL && current->right != NULL) 
	{
     // ������ �ڽ� �Ѹ� �ִ� ��� ������ �ڽ����� ��ü,
      replace_node(current, current->right);
    }
	else if (current->left != NULL && current->right != NULL)
	{
      // ���� �γ� �� �ڽ��� ������, ���� ���ʰ����� ��ü ��Ų��
      replace_node(current, find_left_most_child(current->right));
    } 

    return true;
    
  } 

  /*  �ش��ϴ� ���� ��ã�Ҵٸ� ã���� ������  */   
  else if (comp(value, current->data) == 1)
  {
	  /*    ���� < ã������   */
    return internal_remove(current->right, value, comp);
  } 
  else 
  {
	  /*    ���� > ã������     */
    return internal_remove(current->left, value, comp);
  }

  return false;
}



/*    print Ʈ��   wrapper �޼ҵ� ..   */
template <class T>
void BinarySearchTree<T>::print_Tree()
{
	print_Tree(root ,0 );
}

template <class T>
void BinarySearchTree<T>::print_Tree(Node<T> *node, int depth )
{

		if (depth == 0)
			cout << node->data;
		else
		{
			if (check_endl == true)
			{
				check_endl = false;
				for (int i = 0; i < depth; i++)
					cout << " ";
			}

			if (check_space == true)
			{
				check_space = false;

				for (int i = 0; i < depth * 2 - 1; i++)
					cout << "     ";
			}

			cout << " --- " << node->data;
		}


		if (node->left != NULL)
			print_Tree(node->left, depth + 1);
		else
		{
			if (node->right != NULL)
			{
				cout << " --- " << "0" << endl;
				check_endl = true;
				check_space = true;
			}
		}

		if (node->right != NULL)
			print_Tree(node->right, depth + 1);
		else
		{
			cout << endl;
			check_endl = true;
			check_space = true;
		}



	/*    ���� ǥ�� 
	if( node )
	{

			print_Tree(node->leftChild, space + 1 , 0 );
			for(int i = 0 ; i < space ; i++)
				cout<<"  ";
			cout << node->data <<endl;
			print_Tree(node->rightChild, space + 1 , 1 );
	}
	*/
}
