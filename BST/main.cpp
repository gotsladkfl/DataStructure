#include <iostream>
#include <string>
#include "IOHandler.h"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

using namespace std;


/*      c++ 11 의 람다 식으로 비교에 활용           */

function <int(string&, string&)> comparator = [](string& lValue, string& rValue) ->int
{
    if(lValue < rValue) 
	{
      return 1;
    }
	else if (lValue > rValue) 
	{
      return -1;
    } 
	else 
	{
      return 0;
    }
 };


int main(int argc, char *argv[])
{
  BinarySearchTree<string> bst;
  IOHandler ioh;
  bool firstInput = true;
  string input = "";

  while(true)
  {
	  if( firstInput )
	  {
		  ioh.showMenu();
		  input = ioh.getString();

		  if( input == "0" )
		  {
			  cout<<"종료합니다"<<endl;
			  break;
		  }

		  firstInput = false;
		  bst.insert(input,comparator);

		  while( true )
		  {
			  input = ioh.getString();
			  if( input == "0" )
			  {
				  firstInput = true;
				  bst.print_Tree();              // 출력
				  bst =  BinarySearchTree<string>();
				  break;
			  }
			 bst.insert(input,comparator);
		  }
	  }
  }
  return 0;
}