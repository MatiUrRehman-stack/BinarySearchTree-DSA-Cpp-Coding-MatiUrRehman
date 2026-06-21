template <class type>
class Node{
private:
   type data;
   Node *left_child;
   Node *right_child;
public:
   Node(type t) : data(t), left_child(nullptr), right_child(nullptr){}

   const type& get_data()const{return this->data;}
   Node *get_left()const{return this->left_child;}
   Node *get_right()const{return this->right_child;}


   void set_data(type d){this->data = d;}
   void set_left(Node *l){this->left_child = l;}
   void set_right(Node *r){this->right_child = r;}
};

//Node class for BST implemented using templete functionality
//so that it can handle every type of data int, float, char, string, double, short e.t.c.