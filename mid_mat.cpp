#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int mat[m][n];
    for(int i=0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0;i<m;i++){
        if(mat[i][0] < min){
            min = mat[i][0];
        }

        if(mat[i][n-1] > max){
            max = mat[i][n-1];
        }
    }
    int desired = (m * n + 1) / 2;
    while(min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        for (int i = 0; i < m; ++i)
            place += upper_bound(mat[i], mat[i]+n, mid) - mat[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    cout<<min<<endl;

    return 0;
}