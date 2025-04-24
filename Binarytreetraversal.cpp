#include <iostream>
using namespace std;
class Node{
public:
    int data;
    //we used her pointer to set data in run time
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

    //Inorder
void InordertraverseTree(Node* root){
    if (root == nullptr)
     return;
    InordertraverseTree(root->left);
    cout<<root->data<<"\t";
    InordertraverseTree(root->right);
}
    //Preorder
void PreordertraverseTree(Node* root){
    if(root == nullptr)
        return ;
    cout<<root->data<<"\t";
    InordertraverseTree(root->left);
    InordertraverseTree(root->right);
}
    //Postorder
void PostordertraverseTree(Node* root){
    if(root == nullptr)
    return;
    PostordertraverseTree(root->left);
    PostordertraverseTree(root->right);
    cout<<root->data<<"\t";
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    cout<<"Inorder Traversal: ";
    InordertraverseTree(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    PreordertraverseTree(root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    PostordertraverseTree(root);
    cout<<endl;

    
    return 0;
}