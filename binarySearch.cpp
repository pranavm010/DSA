#include<iostream>
using namespace std;

bool binarySearchF(int arr[],int target,int start,int end){

    int mid = (start) + (end - start)/2;

    while(start <= end){
        if(mid == target)
            return true;

        else if(mid < target){
            start = mid + 1;
            return binarySearchF(arr,target,start,end);
        }
        else{
            end = mid -1;
            return binarySearchF(arr,target,start,end);
        }
    }
    return false;
}

int main(){

    int arr[10] = {1,2,5,7,11,16,20,25,30,75};
    int target;
    cin>>target;

    int start = arr[0];
    int end = arr[9];

    bool ans = binarySearchF(arr,target,start,end);
    //cout<< ans << endl;
    if(1)
        cout<<"target found";
    else
        cout<<"target not found";
}