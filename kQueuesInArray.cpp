#include<iostream>
using namespace std;

class queue{

    public:
        int freeSpot;
        int *arr;
        int *front;
        int *rear;
        int *next;

    public:

        queue(int n, int k){

            freeSpot = 0;
            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];


            for(int i=0;i<k;i++){
                front[i] = -1;
            }

            for(int i =0;i<n-1;i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }



        void enqueue(int element, int q){

            if(freeSpot == -1){

                cout<<"Queue overflow."<<endl;
                return;
            }

            int index = freeSpot;
            freeSpot = next[index];

            if(front[q-1] == -1){
                front[q-1] = index;
            }

            else{

                next[rear[q-1]] = index;
            }

            rear[q-1] = index;
            arr[index] = element;

        }


        int dequeue(int q){

            if(front[q-1] == -1){
                cout<<"Queue underflow."<<endl;
                return -1;
            }

            int index = front[q-1];

            front[q-1] = next[index];

            next[freeSpot] = index;
            freeSpot = index;

            arr[index] = -1;
            return arr[index];
        }

        void printArray(int n){
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    
    
};

int main()
{
    queue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);
    q.printArray(10);

    cout << q.dequeue(1) << endl;
    q.printArray(10);
    cout << q.dequeue(2) << endl;
    q.printArray(10);
    cout << q.dequeue(1) << endl;
    q.printArray(10);
    cout << q.dequeue(1) << endl;

    q.printArray(10);

    cout << q.dequeue(1) << endl;


}