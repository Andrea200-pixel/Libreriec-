#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int d){
        data=d;
        left=right=nullptr;
    }
int getData(){
    return data;
}
Node* getLeft() const {
    return left;
}
Node* getRight() const {
    return right;
}
int setData(int n){
    data=n;
    return data;
}
Node* setLeft(Node* l){
    left=l;
    return left;
}
Node* setRight(Node* r){
    right=r;
    return right;
}
bool isLeaf(){
    if(left!=nullptr&&right!=nullptr)return false;
    if(left!=nullptr||right!=nullptr)return false;
    else return true;
}
};
class BST {
private:
    Node* root;
    int numNodi;
public:
    BST(int nn){
    root=nullptr;
    numNodi=nn;
}
void isEmpty(){
    if(root==nullptr)cout<<"l albero e vuoto"<<endl;
    else cout<<"l albero non e vuoto"<<endl;

}
int size(const Node* root){
    if(root==nullptr)return 0;
    return 1+size(root->getLeft())+size(root->getRight());
}
Node* insert(Node* root,int key){
    if(root->getData()=key)return root;
    if(root==nullptr){
        Node* newNode=new Node(key);
        return newNode;
    }
}
Node* search(Node* root,int key){
    if(root==nullptr||root->getData()==key)return root;
    if(key<root->getData())return search(root->getLeft(),key);
    return search(root->getRight(),key);
}
void inOrder(Node* root){
    if(root!=nullptr){
        inOrder(root->getLeft());
        cout<<root->getData()<<" ";
        inOrder(root->getRight());
    }
}
int height(Node* root){
    if(root==nullptr)return 0;
    else{
        int lheight=height(root->getLeft());
        int rheight=height(root->getRight());
        if(lheight>rheight)return lheight+1;
        else if(lheight<rheight)return rheight+1;
        else return lheight+1;
    }
}
void minimo(Node* root){
    if(root==nullptr)return;
    while(root->getLeft()!=nullptr){
        root=root->getleft;
    }
}
void massimo(Node* root){
    if(root==nullptr)return;
    while(root->getRight()!=nullptr){
        root=root->getRight();
    }
}
Node* remove(Node* root,int key){
    if(root==nullptr)return nullptr;
    if(key<root->getData())remove(root->getLeft(),key);
    else if(key>root->getData())remove(root->getRight(),key);
    else{
        if(root->getLeft()==nullptr){
            Node* temp=root->getRight();
            delete root;
            root=temp;
            return nullptr;
        }
        else if(root->getRight()==nullptr){
            Node* temp=root->getLeft();
            delete root;
            root=temp;
        }
        else{
            Node* temp=minimo(root->getRight());
            root->setData(temp->getData());
            remove(root->getRight(),temp->getData());
        }
    }
}
void svuota(Node* root){
    if(root==nullptr)return;
    svuota(root->getLeft());
    svuota(root->getRight());
    delete root;
    root=nullptr;
}
int contaFoglie(Node* root){
    if(root==nullptr)return 0;
    if(root->isLeaf())return 1;
    return contaFoglie(root->getLeft()) + contaFoglie(root->getRight());
}
int contaIntervallo(Node* root,int low,int high){
    if(root==nullptr)return 0;
    if(root->getData()<low)return contaInterallo(root->getRight(),low,high);
    if(root->getData()>high)return contaIntervallo(root->getLeft(),low,high);
    return 1+contaIntervallo(root->getLeft(),low,high)+contaIntervallo(root->getRight(),low,high);
} 
};