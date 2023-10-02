#include<iostream>
using namespace std;

void mergeSolve(int arr[],int s,int e){

    int mid = (s+e)/2;

    int length1 = mid - s +1;
    int length2 = e - mid;

    int *first = new int[length1];
    int *second = new int[length2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<length1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<length2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < length1 && index2 < length2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < length1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < length2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int arr[], int s, int e){

    if(s >= e)
        return;

    int mid = (s+e)/2;
    //dividing into left sub part.
    mergeSort(arr,s,mid);

    //dividing into right sub part.
    mergeSort(arr,mid+1,e);

    //merging the sorted arrays.
    mergeSolve(arr,s,e);

}

int main()
{
    int arr[7] = {5,2,9,4,3,10,1};
    int n = 7;
    mergeSort(arr,0,n-1);
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
}