#include<iostream>
using namespace std;

class DoubleNode{
    public:
    int data;
    DoubleNode* prev;
    DoubleNode* next;

    DoubleNode(int data){

        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};


void insertAtHead(DoubleNode* &head){

    cout<<"Enter data to enter:";
    int data;
    cin>>data;
    if(data == -1){
        return;
    }
    DoubleNode* newnode = new DoubleNode(data);
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
    insertAtHead(head);
}

void insertAtEnd(DoubleNode* &head){

    cout<<"Enter data to insert:";
    int data;
    cin>>data;

    DoubleNode* newnode = new DoubleNode(data);

    if(data == -1){
        return;
    }
    DoubleNode* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newnode;
    newnode -> prev = temp;

    insertAtEnd(head);

}

void insertInMiddle(DoubleNode* &head){

    DoubleNode* temp = head;
    cout<<"Enter position to insert data:";
    int pos;
    cin>>pos;

    if(pos == 1){
        insertAtHead(head);
        return;
    }

    for(int i = 1;i<pos-1;i++){
        temp = temp -> next;
    }

    if(temp -> next == NULL){
        insertAtEnd(temp);
        return;
    }
    cout<<"Enter data to insert:";
    int data;
    cin>>data;

    DoubleNode* newnode= new DoubleNode(data);

    newnode -> next = (temp->next);
    (temp -> next) -> prev = newnode;
    temp -> next = newnode;
    newnode -> prev = temp;

}

void deleteNode(DoubleNode* &head, int val){

    DoubleNode* temp1 = head;
    DoubleNode* temp2 = head;

    while(temp2 -> data != val){
        temp1 = temp2;
        temp2 = temp2 -> next;
    }

    if(temp1 == temp2){
        (temp1 -> next) -> prev = NULL;
        //temp1 -> next = head;
        head = temp1 -> next;
        temp2 -> next = NULL;
        temp1 -> next = NULL;
        delete temp1,temp2;
    }

    else if(temp2 -> next == NULL){
        temp1 -> next = NULL;
        temp2 ->prev = NULL;
        delete temp2;
    }

    else{
        
        temp1 -> next = temp2 -> next;
        (temp2 -> next) -> prev = temp1;
        temp2 -> next = NULL;
        temp2 -> prev = NULL;
        delete temp2;
        
    }
}

void print(DoubleNode* head){
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
    
}

void printReverse(DoubleNode* head){
    DoubleNode* temp = head;
    while(temp ->next  != NULL){
        temp = temp -> next;
    }

    while(temp  != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> prev;
    }
    cout<<endl;

}


int main(){
    DoubleNode* head = new DoubleNode(10);

    //insertion at head
    insertAtHead(head);
    cout<<"Printing as it is:"<<" ";
    print(head);
    cout<<"Printing reverse:"<<" ";
    printReverse(head);

    //insertion at end
    insertAtEnd(head);
    print(head);
    printReverse(head);

    //insertion in middle position
    insertInMiddle(head);
    print(head);
    printReverse(head);

    //After deletion of any value
    cout<<"After deletion:"<<endl;
    deleteNode(head,25);
    print(head);
    printReverse(head);
}