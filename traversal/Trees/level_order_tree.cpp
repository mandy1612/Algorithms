// using queue
#include<iostream>
#include<queue>
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

void levelOrder(Node* root){
    if(root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* tmp = q.front();
        cout<<tmp->val<<" ";
        q.pop();

        if(tmp->left != nullptr)
            q.push(tmp->left);
        if(tmp->right != nullptr)
            q.push(tmp->right);
    }
}

int main(){
    Node* root = new Node(7);
    vector<int> v;
    int tmp;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        cin>>tmp;
        v.push_back(v);
        cout<<"Would you like to enter more?(Y/N)";
        cin>>ch;
    }
    for(int i=0;i<v.size();i++){
        root = insert(root,v[i]);
    }
    levelOrder(root);
    return 0;
}