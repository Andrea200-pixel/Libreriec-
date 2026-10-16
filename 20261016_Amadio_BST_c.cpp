#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node() {
        left=right=nullptr;
        data=0;
    }
    Node(int val) {
        data=val;
        left=right=nullptr;
    }
};
Node* insert(Node* root, int val) {
    if (root==nullptr) {
        root=new Node(val);
    }
    if (val<root->data) {
        root -> left=insert(root->left,val);
    }else if ( val>root->data) {
        root -> right =insert(root->right,val);
    }
    return root;
}
bool search(Node* root, int val) {
    if (root==nullptr) {
        return false;
    }
    if (root->data==val) {
        return true;
    }
    if (val<root->data) {
        return search(root->left,val);
    }
    if (val>root->data) {
        return search(root->right,val);
    }
    return false;
}
int main() {
    Node*root=nullptr;
    root=insert(root,5);
    root=insert(root,9);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    int key;
    cin>>key;
    if (search(root,key)) {
        cout<<"trovato"<<endl;
        return 0;
    }else{
        cout<<"non trovato"<<endl;
        return 0;
    }
    system("pause");
    return 0;
}