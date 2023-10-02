#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* next;

    Node(int data){

        this->data = data;
        this->next = NULL;
    }
};


class Stack{

    Node* top;

    public:
        void push(int data){

            Node* temp = new Node(data);
            temp -> next = top;
            top = temp;
            cout<<"Pushed element "<<data<<" successfully."<<endl;
        }

        void pop(){

            if(!top){
                cout<<"Stack underflow."<<endl;
            }

            else{
                cout<<"Popped the element "<<top->data<<endl;
                Node* temp = top;
                temp = top->next;
                delete(top);
                top = temp;
            }
        }

        void peek(){

            if(!top){
                cout<<"Stack is empty"<<endl;
            }
            else{

                cout<<"Top element is:"<<top->data<<endl;
            }
        }

        void isEmpty(){

            if(!top){
                cout<<"Stack is empty."<<endl;
            }
            else{
                cout<<"Stack is not empty."<<endl;
            }
        }
};

int main(){

    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    st.peek();
    st.pop();
    st.isEmpty();
}