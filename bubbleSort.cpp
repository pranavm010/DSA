#include<bits/stdc++.h>
using namespace std;

void bubbleSorts(vector<int>& arr, int size){
    
    bool swapped = false;
    for(int i = 1;i<size;i++){
        for(int j = 0;j<size-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            //already sorted.
            break;
        }
    }
    
    
}

void usingRecursion(vector<int>& arr,int size){

    if(size == 0 || size == 1)
        return ;
    
    for(int i = 0;i<size-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    usingRecursion(arr,size-1);

}

int main(){

    vector<int> arr{10,1,7,14,6,9};
    bubbleSorts(arr, 6); 
    //printing the array1
    cout<<"Sorted array using loops is:"<<endl;
    for(int k = 0;k<arr.size();k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
    usingRecursion(arr,6);
    //printing the array2
    cout<<"Sorted array using recursion is:"<<endl;
    for(int k = 0;k<arr.size();k++){
        cout<<arr[k]<<" ";
    }
}