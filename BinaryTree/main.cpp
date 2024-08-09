
#include <iostream>
struct node{
    int key;
    node *left;
    node *right;
};

node *creatRoot(){
    //the logica are numbers that smaller
    //50/root will go left else to right
    node *root=new node();
    root->key=50;
    root->left=NULL;
    root->right=NULL;
    return root;
}
node *createLeft(int this_key,node *this_left){
    this_left->left=new node();
    this_left->left->key=this_key;
    this_left->left->left=NULL;
    this_left->left->right=NULL;
    return this_left;
}
node *createRight(int this_key,node *this_right){
    this_right->right=new node();
    this_right->right->key=this_key;
    this_right->right->left=NULL;
    this_right->right->right=NULL;
    return this_right;
}
node *addToNode(int key ,node *p_node){
    // if first node tree is large or equal 50
    // than next node pointer to right->left or right->right,
    //another case if less than 50 next node is ponter to left->left or left->right.
    std::cout<<p_node->key<<"\n";
    if(key<p_node->key){// the root
        
            if(p_node->left == NULL){
                p_node= createLeft(key, p_node);
                return p_node;
               // break;
            }
        p_node->left= addToNode(key, p_node->left);// next node
          
        
        }else if(key>=p_node->key){
            if(p_node->right == NULL){
                p_node= createRight(key, p_node);
                return p_node;
              //  break;
            }
           
            p_node->right= addToNode(key, p_node->right);
        }
           

    return p_node;
}

node *creatRoot();
node *createLeft(int this_key,node *this_left);
node *createRight(int this_key,node *this_right);
node *addToNode(int key ,node *p_node);
int main(int argc, const char * argv[]) {
    
    int key=35;
    node *mroot= creatRoot();
    mroot= addToNode(key, mroot);
    mroot= addToNode(key-2, mroot);
    mroot= addToNode(key+1, mroot);
    delete mroot;
    return 0;
}


