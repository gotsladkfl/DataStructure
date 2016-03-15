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

/*    BST 에서 제일 왼쪽 자식으로 대체하려고 제일 왼쪽째 노드 찾기   */
template <typename T>
Node<T>*& BinarySearchTree<T>::find_left_most_child(Node<T>*& current)
{
  while(current->left)
  {
    current = current->left;
  }
  
  return current;
}

/*      새로운 노드를 기존의 노드랑 대체        */

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

/*          추가    wrapper method           */
template <typename T>
bool BinarySearchTree<T>::insert(T value, function<int(T&, T&)>& comp) 
{
  return internal_insert(root, value, comp);
}

template <typename T>
bool BinarySearchTree<T>::internal_insert(Node<T>*& current, T value,
                                          function<int(T&, T&)>& comp) 
{
  /*       재귀적인 방법으로 현재 기준 노드에서 크면 오른쪽 작으면 왼쪽..이런식으로 재귀를 타고 들어감   */

	/*  첫 노드인 경우  */
  if (current == NULL) 
  {
    current = new Node<T>(value);
    return true;
  } 
  /*  기준 값이 더 크면 입력 값을 왼쪽에 */
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



/*           삭제 wrapper method           */
template <typename T>
bool BinarySearchTree<T>::remove(T value, function<int(T&, T&)>& comp)
{
  return internal_remove(root, value, comp);
}

template <typename T>
bool BinarySearchTree<T>::internal_remove(Node<T>*& current, T value,
                                          function<int(T&, T&)>& comp) 
{
	/*    찾았는데 딸린 자식이 1. 없을 때 2. 하나만 있을 때 ( 좌,우 ) 3. 둘다 있을 때   */
  if (comp(current->data, value) == 0) 
  {
    if (current->left == NULL && current->right == NULL) 
	{
      // 1. 만약 자식이 하나도 없는 노드는 그냥 삭제시키면 됨
      delete current;
      current = NULL;
    } 
	else if (current->left != NULL && current->right == NULL) 
	{
      // 왼쪽 자식이 한명만 있는 경우 왼쪽 자식으로 대체,
      replace_node(current, current->left);
    }
	else if (current->left == NULL && current->right != NULL) 
	{
     // 오른쪽 자식 한명만 있는 경우 오른쪽 자식으로 대체,
      replace_node(current, current->right);
    }
	else if (current->left != NULL && current->right != NULL)
	{
      // 만약 두놈 다 자식이 있으면, 가장 왼쪽값으로 대체 시킨다
      replace_node(current, find_left_most_child(current->right));
    } 

    return true;
    
  } 

  /*  해당하는 값을 못찾았다면 찾으러 가보자  */   
  else if (comp(value, current->data) == 1)
  {
	  /*    기준 < 찾으려는   */
    return internal_remove(current->right, value, comp);
  } 
  else 
  {
	  /*    기준 > 찾으려는     */
    return internal_remove(current->left, value, comp);
  }

  return false;
}



/*    print 트리   wrapper 메소드 ..   */
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



	/*    세로 표현 
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
