#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionSrt(vector<int>& arr, int size){
    
    for(int i = 0;i<size;i++)
    {
        int smallestIndex = i;
        for(int j = i+1;j<size;j++)
        {
            if(arr[j] < arr[smallestIndex])
            smallestIndex = j;
        }
        swap(arr[smallestIndex], arr[i]);
    }
    
}

void usingRecursion(int arry[], int size){

    //base case
    if(size == 0 || size == 1){
        return;
    }

    int small = 0;
    int j;
    for(j = 0;j<size;j++){
        if(arry[j] < arry[small])
            small = j;
    }
    swap(arry[0],arry[small]);
    usingRecursion(arry+1,size-1);
}

int main()
{
    vector<int> arr{50,5,2,15,60,42};
    int arry[6] = {50,5,2,15,60,42};
    
    selectionSrt(arr,6);
    cout<<"Printing the sorted array using loops"<<endl;
    for(int k = 0;k<6;k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;

    usingRecursion(arry,6);
    cout<<"Printing the sorted array using recursion"<<endl;
    for(int k = 0;k<6;k++){
        cout<<arry[k]<<" ";
    }

}