#include<iostream>
using namespace std;

void sayDig(int n, string arr[]){

    if(n == 0)
        return;

    int i = n % 10;
    n = n / 10;
    sayDig(n,arr);
    cout<<arr[i]<<" ";
}

int main(){

    int n;
    cin>>n;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    sayDig(n,arr);

}