#include<bits/stdc++.h>
using namespace std;
int main()
{
    char arr[] = {'H','e','l','l','o','W','o','r','l','d'};
    vector<char> vec(begin(arr),end(arr));
    for(int i = vec.size()-1;i>=0;i--)
    {
        cout<<vec[i]<<" ";
    }
}