#include<bits/stdc++.h>
using namespace std;

class Stack{

    public:
    int *arr;
    int size;
    int top;

    Stack(int size){

        this->size = size;
        arr = new int[size];
        top = -1;
    }


    void push(int data){

        if(top < size - 1){
            top = top + 1;
            arr[top] = data;
            cout<<"Added the element "<<data<<endl;
        }

        else{
            cout<<"Stack overflow, can not add the data."<<endl;
        }
        
    }

    void isEmpty(){

        if(top == -1){
            cout<<"Stack is empty."<<endl;
        }
        else{
            cout<<"Stack is not empty"<<endl;
        }
    }

    void peek(){

        if(top == -1){
            cout<<"Stack is empty, can not retrieve element."<<endl;
        }
        else{
            cout<<"Top element is:"<<arr[top]<<endl;
        }
        
    }

    void pop(){

        if(top >= 0){
            cout<<"Popped out "<<arr[top]<<endl;
            top--;
           
        }
        else{
            cout<<"Stack Underflow."<<endl;
        }
    }
};

int main(){

    Stack st(5);

    st.push(2);
    st.push(5);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);

    st.pop();
    st.peek();
    st.isEmpty();
    
}