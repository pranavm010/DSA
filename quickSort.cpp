#include<bits/stdc++.h>
using namespace std;


int partition(int arr[], int start, int end){
    int pivot = arr[start];

    int count = 0;

    for(int i =start+1;i<=end;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = count + start;
    swap(arr[pivotIndex],arr[start]);

    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quikSort(int arr[], int low, int high){

    if(low >= high){
        return;
    }
    int pi = partition(arr, low, high);

    quikSort(arr, low, pi-1);
    quikSort(arr,pi+1,high);
}


int main(){

    int size;
    cout<<"Enter the number of elements you want:"<<endl;
    cin>>size;

    int arr[size];
    int n = size;

    for(int i =0;i<size;i++){
        arr[i] = rand() % 1000;
    }

    quikSort(arr,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;

}