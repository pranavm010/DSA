#include<bits/stdc++.h>
using namespace std;
string isPalindrome(string str1)
{
    string str2 = str1;
    reverse(str2.begin(),str2.end());
    if(str1 == str2)
    {
        return "Yes";
    }
    else{
        return "No";
    }
}
int main()
{
    string str1;
    cin>>str1;
    cout<<isPalindrome(str1);
}