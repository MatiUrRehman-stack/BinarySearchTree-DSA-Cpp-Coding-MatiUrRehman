#include <iostream>
#include "BSTClass.hpp"

using namespace std;

int main(){
   BST<int> tree;
   tree.insert(25);
   tree.insert(25);
   tree.insert(11);
   tree.insert(50);
   tree.insert(26);
   tree.insert(30);   
   
   // tree.printInorder();
   // tree.printPreorder();
   // tree.printPostorder();
   //tree.printLevelorder();
   tree.minimum();
   tree.maximum();
}