#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
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

Node* insertBST(Node* root,int data){

    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root->data < data){
        root -> right = insertBST(root->right,data);
    }

    else{
        root -> left = insertBST(root->left,data);
    }

    return root;
}

void takeinput(Node* &root){
    
    int data;
    cin>>data;

    while(data != -1){
        root = insertBST(root,data);
        cin>>data;
    }
}

Node* minVal(Node* root){
    while(root->left){
        root = root -> left;
    }

    return root;
}

Node* deleteNode(Node* &root, int element){

    if(root == NULL){
        return root;
    }

    if(root->data == element){

        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        if(root->left && !root->right){

            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->right && !root->left){

            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left && root->right){

            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right,mini);
            return root;
        }
    }
    else if(root->data > element){
        deleteNode(root->left,element);
    }
    else{
        deleteNode(root->right,element);
    }
}

int main(){

    Node* root = NULL;

    cout<< "Enter data to insert into bst:"<<endl;
    takeinput(root);

    cout<<"Level order traversal:"<<endl;
    levelOrderTraversal(root);

    root = deleteNode(root,10);
    levelOrderTraversal(root);
}