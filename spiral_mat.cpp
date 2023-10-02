#include<iostream>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int mat[m][n];

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    int p = 0 , l = 0;
    while(p<m && l<n){
        
        for(int i = p;i<n;i++){
            cout<<mat[p][i]<<" ";
        }
        p++;

        for(int i=p;i<m;i++){
            cout<<mat[i][n-1]<< " ";
        }
        n--;

        if(p<m){
            for(int i=n-1;i>=l;i--){
                cout<<mat[m-1][i]<<" ";
            }

            m--;
        }
        if(l<n){
            for(int i=m-1;i>=p;i--){
                cout<<mat[i][l]<<" ";
            }
            l++;
        }
    }
    return 0;
}