#include<bits/stdc++.h>
using namespace std;


vector<int> sum(vector<int>& v1,vector<int>& v2,int m, int n){

    int carry = 0;
    vector<int> ans;
    int i = m-1;
    int j = n-1;

    while(i >= 0 && j >= 0){
        int sum = v1[i] + v2[j] + carry;
        carry = sum / 10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while(i >= 0){
        int sum = v1[i] + carry;
        carry = carry/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

    while(j >= 0)
    {
        int sum = v2[j] + carry;
        carry = sum/10;
        sum =sum%10;
        ans.push_back(sum);
        j--;
    }

    if(carry != 0){
        ans.push_back(carry);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    vector<int> v1{1,2,3,4};
    vector<int> v2{9,8,7,9};
    int m = v1.size();
    int n = v2.size();
    
    vector<int> v3;
    v3 = sum(v1,v2,m,n);

    for(int i = 0;i<v3.size();i++){
        cout<<v3[i]<<" ";
    }
}