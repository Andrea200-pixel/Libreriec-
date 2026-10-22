#include<iostream>
using namespace std;
Node* findMin(const Node* root){
    if (root==nullptr)return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
Node* findMax(const Node* root){
    if (root==nullptr)return nullptr;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}
int countNodes(const Node* root){
    if(root==nullptr)return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int countLeaves(const Node* root){
    if(root==nullptr)return 0;
    if(root->left==nullptr && root->right==nullptr)return 1;
    return countLeaves(root->left)+countLeaves(root->right);
}
int countInRange(const Node* root,int min,int max){
    if(root==nullptr)return 0;
    if(root->data<min) return countInRange(root->left,min,max);
    if(root->data>max) return countInRange(root->right,min,max);
    return 1+countInRange(root->left,min,max)+countInRange(root->right,min,max);
}