#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* createTree(node* root){

    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
        return NULL;

    cout<<"Enter data to insert left of "<<data<<endl;
    root ->left = createTree(root -> left);
    cout<<"Enter data to insert right of "<<data<<endl;
    root -> right = createTree(root -> right);

    return root;

}

void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }    
}

void inorderTraversal(node* root){

    if(root == NULL){
        return;
    }

    inorderTraversal(root -> left);
    cout<<root -> data <<" ";
    inorderTraversal(root -> right);
}

void preOrderTraversal(node* root){

    if(root == NULL){
        return;
    }

    cout<<root -> data<<" ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(node* root){

    if(root == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout<< root->data<<" ";
}

int main(){

    node* root = NULL;
    root = createTree(root);

    cout<<"Level order traversal is:"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"inorderTraversal is:"<<endl;
    inorderTraversal(root);

}


// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1