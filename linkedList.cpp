// Linked list is a (Dynamic) linear data structure which is collection of nodes. Nodes contain data and address of next node.
// Why linked...beacause we cannot change the size of array at runtime but there is no limitation on size of linked list.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* insertAtHead(Node* &head){

    cout<< "Enter data to inserted:";
    int data;
    cin >> data;
    if(data == -1){
        return head;
    }
    Node* newnode = new Node(data);
    newnode ->next = head;
    head = newnode;
    insertAtHead(head);
    return head;
}

void insertAtEnd(Node* &head){

    Node* temp = head;
    cout << "Enter data to insert:";
    int data;
    cin>>data;

    if(data == -1){
        return;
    }

    Node* newnode = new Node(data);
    temp ->next = newnode;
    temp = newnode;
    insertAtEnd(temp);
}

void insertInMiddle(Node* head){

    Node* temp = head;
    cout<<"Insert position at which you want to add the node:";
    int pos;
    cin>>pos;
    cout<<"Enter data for the node:";
    int data;
    cin>>data;
    Node* newnode = new Node(data);
    if(pos == 1)
        insertAtHead(newnode);

    for(int i = 1;i<pos-1;i++){
        temp = temp -> next;
    }

    newnode -> next = temp -> next;
    temp -> next = newnode;
}

Node* deleteNode(Node* &head, int value){

    Node* temp1 = head;
    Node* temp2 = temp1;
    while(temp2 -> data != value){
        temp1 = temp2;
        temp2 = temp2 -> next;
    }

    if(temp1 == temp2){ 
        head = temp1 -> next;
        temp1 -> next = NULL;
        delete temp1,temp2;
        return head;
    }

    temp1 -> next = temp2 -> next;
    temp2 -> next = NULL;
    delete temp2;
    return head;
}

void printLinkedList(Node* head){

    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
    
}

int main(){

    Node* head = new Node(10);
    //cout << temp1->data << endl;

    //Node* temp = insertAtHead(head);
    insertAtEnd(head);
    //insertInMiddle(head);
    cout<<"Before deletion:"<<" ";
    printLinkedList(head);
    deleteNode(head,10);
    cout<<"After deletion:"<<" ";
    printLinkedList(head);

}