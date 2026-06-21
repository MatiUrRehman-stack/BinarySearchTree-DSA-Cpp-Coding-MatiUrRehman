#include "BSTNode.hpp"
#include "TemplateQueue.hpp"


template <class T>
class BST{
private:
   Node<T> *root;

   
   Node<T>* insertHelper(T val,Node<T> *ptr){
      if(ptr == nullptr){return new Node<T>(val);}
      
      if (val < ptr->get_data()) {
         ptr->set_left(insertHelper(val, ptr->get_left()));
      } else if(val > ptr->get_data()) {
         ptr->set_right(insertHelper(val, ptr->get_right()));
      }else{
         std::cout<<"Cant add : already exist\n";;
      }
      
      return ptr;
   }
//=======destructer helper
   void destroyTree(Node<T> *ptr){
      if(ptr == nullptr){
         return;
      }

      destroyTree(ptr->get_left());
      destroyTree(ptr->get_right());

      delete ptr;
   }
//======  left ->  root -> right
   void Inorder(Node<T> *ptr){
      if(ptr == nullptr){return;}
      else{
         Inorder(ptr->get_left());
         std::cout<<ptr->get_data()<<" ";
         Inorder(ptr->get_right());
      }
   }   
//======  root -> left -> right
   void Preorder(Node<T> *ptr){
      if(ptr == nullptr){return;}
      else{
         std::cout<<ptr->get_data()<<" ";
         Preorder(ptr->get_left());
         Preorder(ptr->get_right());
      }
   }   
//======  left  -> right ->  roote
   void Postorder(Node<T> *ptr){
      if(ptr == nullptr){return;}
      else{
         Postorder(ptr->get_left());
         Postorder(ptr->get_right());
         std::cout<<ptr->get_data()<<" ";
      }
   }   
//====== level order traversal
   void Levelorder(Node<T> *ptr, T val){
      if(ptr == nullptr){return;}
      else{
         Queue<Node<T>*> q;
         q.enqueue(root);
         while(!q.isEmpty()){
            Node<T> *curr = q.front();
            q.dequeue();
            std::cout<<curr->get_data()<<" ";
            if(curr->get_left()){
               q.enqueue(curr->get_left());
            }
            if(curr->get_right()){
               q.enqueue(curr->get_right());
            }
         }
      }
   }
//===Removing Node from BST
   Node<T>* del(Node<T> *ptr){
      if(ptr){return ptr;}
      if(val < ptr->get_data()){
         ptr->set_left(del(ptr->get_left(), val)); 
      }else if(val > ptr->get_data()){
         ptr->set_right(del(ptr->get_right(), val));
      }else if(!ptr->get_left()){
         Node<T> *temp = ptr->get_right();
         delete ptr;
         return temp;
      }else if(!ptr->get_right()){
         Node<T> *temp = ptr->get_left();
         delete ptr;
         return temp;
      }else{
         Node<t> *temp = min(ptr->get_right());
         ptr->set_data(temp->get_data());
         ptr->set_right(del(ptr->get_right(), temp->get_data()));
      }
      return ptr;
   }
//=========Finding minium and maximum
   Node<T> *min(Node<T> *ptr){
      if(ptr == nullptr){
         return ptr;
      }
      while(ptr && ptr->get_left()){
         ptr = min(ptr->get_left());
      }
      return ptr;
   }
   Node<T> *max(Node<T> *ptr){
      if(ptr == nullptr){
         return ptr;
      }
      while(ptr && ptr->get_right()){
         ptr = max(ptr->get_right());
      }
      return ptr;
   }

public:
//Constructer and Destructer
   BST() : root(nullptr){}
   ~BST(){destroyTree(this->root);this->root = nullptr;}
//====getter function
   Node<T> *get_root(){return this->root;}

//
//insert with function call point to private block
//   
   void insert(T val) {
   this->root = insertHelper(val, this->root);
   }
//Printing functions calling recursive traversal
   void printInorder(){
      if(this->root == nullptr){std::cout<<"tree is empty"<<std::endl;return;}
      Inorder(this->root);
      std::cout<<std::endl;
   }
   void printPreorder(){
      if(this->root == nullptr){std::cout<<"tree is empty"<<std::endl;return;}
      Preorder(this->root);
      std::cout<<std::endl;
   }
   void printPostorder(){
      if(this->root == nullptr){std::cout<<"tree is empty"<<std::endl;return;}
      Postorder(this->root);
      std::cout<<std::endl;
   }
//====Level Order traversal
   void printLevelorder(){
   if(this->root == nullptr){std::cout<<"tree is empty"<<std::endl;return;}
   Levelorder(this->root);
   std::cout<<endl;
}
//=====max an min.
   void minimum(){
      if(this->root == nullptr){std::cout<<"tree is empty"<<std::endl;return;}
      else{
         Node<T> *temp = min(this->root);
         cout<<temp->get_data()<<endl;
      }

   }
   void maximum(){
      if(this->root == nullptr){std::cout<<"tree is empty"<<std::endl;return;}
      else{
         Node<T> *temp = max(this->root);
         cout<<temp->get_data()<<endl;
      }

   }
};
