#include<iostream>
using namespace std;

/*int factorial(int n){
    if(n == 1)
        return 1;
    else{
        n = n * factorial(n-1);
    }
    return n;
}*/

/*int powerOf2(int n){

    if(n == 0){
        return 1;
    }
    else{
        n = 2 * powerOf2(n-1);
    }

    return n;
}*/

/*void printCounting(int n){

    cout<< n <<" ";
    if(n == 1)
        return;
    n = n - 1;
    printCounting(n);
}*/

void printFibonacci(int n, int a, int b){

    cout<< a << " ";
    if(b > n)
        return;
    
    int sum = a + b;
    printFibonacci(n,b,sum);

}

int main(){

    int n;
    cout<<"Enter number till which yo wnt to print fibonacci:";
    cin>>n;
    //int fact = 1;
    //int ans = factorial(n);
    //int ans = powerOf2(n);
    //printCounting(n);
    //cout<<ans;
    int a = 0 , b = 1;
    printFibonacci(n,a,b);

}