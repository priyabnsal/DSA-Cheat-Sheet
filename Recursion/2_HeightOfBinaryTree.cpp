#include<bits/stdc++.h>
using namespace std;
#define COUNT 10 

class node
{
    public:
    int data;
    node* left;
    node* right;
};
node* newNode(int data){
    node* Node =new node();
    Node->data= data;
    Node->left=NULL;
    Node->right=NULL;
    return(Node);
}

void print2DUtil(node *root, int space) 
{ 
    if (root == NULL) 
        return; 

    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->data<<"\n"; 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(node *root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
} 
 
int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = height(node->left);
        int rDepth = height(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
        // return 1+ max(lDepht,rDepth);
    }
}



   
int main(){

    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left = newNode(6); 
    root->left->left->left = newNode(8); 
 
    print2D(root); 

    cout << "Height of tree is " << height(root);
    return 0;
}