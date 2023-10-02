#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){

    //base case
    if(size == 0 || size == 1)
        return true;

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr + 1,size-1);
        return ans;
    }
    
}

int arraySum(int arr[], int size){

    //base case
    if(size <= 0)
        return 0;

    int sum = arr[0] + arraySum(arr + 1,size-1);
    return sum;
}

bool linerSearch(int arr[], int size,int target){
    //base case
    if(size == 0)
        return false;

    if(arr[0] == target)
        return true;
    else{
        bool ans = linerSearch(arr+1,size-1,target);
        return ans;
    }
}

bool binarySearchf(int arr[],int target,int start,int end){

    //base case
    if(start > end)
        return false;

    int mid = (start) + (end - start)/2;

    if(arr[mid] == target){
        return true;
    }

    if(arr[mid] < target){
        return binarySearchf(arr,target,mid+1,end);
    }

    else{
        return binarySearchf(arr,target,start,mid-1);
    }
}

int powerOf(int a, int b){

    //base case1
    if(b == 0)
        return 1;

    if(b == 1)
        return a;

   int ans = powerOf(a, b/2);

   if(b%2 == 0)
    return ans*ans;

   else{
    return a*ans*ans;
   }

}

int main(){

    int arr[8] = {4,5,6,7,8,9,10,11};
    int size = 8;

    /*bool answer = isSorted(arr,size); 
    cout<< answer << endl;*/
    /*int sum = arraySum(arr,size);
    cout<< sum <<endl;*/

    /*int target;
    cin>>target;
    bool answer = linerSearch(arr,size,target);
    cout<< answer <<endl;*/

    /*int target;
    cin>>target;
    int start = 0;
    int end = 7;
    bool answer = binarySearchf(arr,target,start,end);
    cout<<answer<<endl;*/

    int a,b;
    cin>>a>>b;
    int ans = powerOf(a,b);
    cout<<ans;
}