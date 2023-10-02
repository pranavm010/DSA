#include<bits/stdc++.h>
using namespace std;

class heap{

    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insertInHeap(int val){

            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){

                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[index],arr[parent]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void printHeap(){

            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void deleteFromHeap(int val){

            if(size == 0){
                cout<<"Nothing to delete."<<endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i < size){

                int left = 2*i;
                int right = 2*i + 1;

                if(left < size && arr[i] < arr[left]){
                    swap(arr[i],arr[left]);
                    i = left;
                }

                else if(right < size && arr[i] < arr[right]){
                    swap(arr[i],arr[right]);
                    i = right;
                }

                else{
                    return;
                }
            }
        }
};

void heapify(int arr[],int n,int i){

    int largest = i;
    int left = i*2;
    int right = i*2 + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){

    int size = n;

    while(size > 1){

        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main(){

    heap h;
    
    h.insertInHeap(50);
    h.insertInHeap(53);
    h.insertInHeap(55);
    h.insertInHeap(52);
    h.insertInHeap(54);

    h.printHeap();

    h.deleteFromHeap(55);
    h.printHeap();

    int arr[] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i=n/2;i>0;i--){

        heapify(arr,n,i);
    }

    cout<<"Printing array"<<endl;

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);

    cout<<"Printing sorted array"<<endl;

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

}