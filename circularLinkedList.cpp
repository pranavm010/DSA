#include<iostream>
using namespace std;

class Cnode{

    public:
    int data;
    Cnode* next;

    Cnode(int data){

        this -> data = data;
        this -> next = NULL;
    }
};

void insertNode(Cnode* &tail, int element, int data){

    if(tail == NULL){
        Cnode* newnode = new Cnode(data);
        tail = newnode;
        newnode -> next = newnode;
    }

    else{

        Cnode* temp = tail;
        while(temp ->data != element){
            temp = temp -> next;
        }

        Cnode* newnode = new Cnode(data);
        newnode -> next = temp -> next;
        temp -> next = newnode;
        if(tail -> data == element){
            tail = newnode;
        }

    }
}

void deleteNode(Cnode* &tail, int value) {

    if(tail == NULL) {
        cout << " List is empty." << endl;
        return;
    }
    else{
        
        Cnode* prev = tail;
        Cnode* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        if(curr == prev) {
            tail = NULL;
        }

        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

void printCLL(Cnode* tail){

    Cnode* temp = tail;
    temp = temp -> next;

    while(temp != tail){
        cout<< temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<tail -> data<<endl;
}

int main(){

    Cnode* tail = NULL;
    insertNode(tail,5,1);
    printCLL(tail);

    insertNode(tail,1,5);
    printCLL(tail);

    insertNode(tail,5,9);
    printCLL(tail);

    insertNode(tail,9,14);
    printCLL(tail);

    insertNode(tail,14,19);
    printCLL(tail);

    deleteNode(tail,19);
    printCLL(tail);


}