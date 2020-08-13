// using queue
#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int val;
    Node *left,*right;

    Node(int v) : val(v),left(nullptr),right(nullptr) {}
};

Node* insert(Node* root,int v){
    if(root == nullptr){
        return new Node(v);
    }
    if(v > root->val){
        root->right = insert(root->right,v);
    }
    else{
        root->left = insert(root->left,v);
    }
    return root;
}

void preorder(Node* root){
    if(root != nullptr){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if(root != nullptr){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

int main(){
    Node* root = new Node(7);
    vector<int> v;
    int tmp;
    char ch = 'y'
    while (ch == 'Y' || ch == 'y'){
        cin>>tmp;
        v.push_back(tmp);
        cout<<"Would you like to enter more?(Y/N)";
        cin>>ch;
    }
    for(int i=0;i<v.size();i++){
        root = insert(root,v[i]);
    }
    cout<<"1. PreOrder\n2. Inorder\n3. PostOrder\nEnter to traverse";
    cin>>tmp;
    switch(tmp){
        case 1: preorder(root);
                break;
        case 2: inorder(root);
                break;
        case 3: postorder(root);
                break;
        default: break;
    }
    return 0;
}