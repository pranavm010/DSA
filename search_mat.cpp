#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int mat[m][n];
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int target;
    cin>>target;
    bool flag = false;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(mat[i][j] == target)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag)
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}