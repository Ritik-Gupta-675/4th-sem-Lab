#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
int getheight(Node* root){
    if(root==NULL)return 0;
    return root->height;
}
int balancefactor(Node* root){
    if(root==NULL)return 0;
    getheight(root->right) -getheight(root->left);
}
void updateHeight(Node* node){
    node->height = 1 + max(getheight(node->left) , getheight(node->right));
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}
Node* insert(Node* root, int data) {
    if (!root) return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root; 
    updateHeight(root);
    int balance = balancefactor(root);
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data<< " ";
        inorder(root->right);
    }
}
int main(){
    Node* root = new Node(5);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    cout << "Inorder traversal after half insertion: ";
    inorder(root);
    cout << endl;
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Inorder traversal after  full insertion: ";
    inorder(root);
    cout << endl;

}