#include<bits/stdc++.h>
using namespace std;

int N = 1000000;
bool sieveArr[1000001];

void createSieve(){
    for(int i = 2;i < N;i++){
        sieveArr[i] == true;
    }

    for(int i = 2;i*i <= 1000000;i++){
        if(sieveArr[i] == true){
            for(int j = i*i;j <= N;j+=i){
                sieveArr[j] = false;
            }
        }
    }

}

vector<int> generatePrime(int n){

    vector<int> ps;
    for(int i = 2;i<=n;i++){
        if(sieveArr[i] == true){
            ps.push_back(i);
        }
    }
    return ps;

}
int main(){
    createSieve();
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        //step1:
        vector<int> prime = generatePrime(sqrt(r));

        /*for(int i = 0;i < prime.size();i++)
            cout<<prime[i]<<" ";
            */

        //step2:
        int dummy[r - l + 1];
        for(int i=0;i<r-l+1;i++){
            dummy[i] == 1;
        }

        //step3:
        for(auto pr:prime){
            int firstMultiple = (l/pr)*pr;
            if(firstMultiple < l)
                firstMultiple += pr;
            for(int j = max(firstMultiple, pr*pr);j <= r;j+=pr){
                dummy[j - l] = 0;
            }
        }

        //step4:
        for(int j = l;j<=r;j++){
            if(dummy[j] == 1)
                cout<<dummy[j]<<" ";
        }

    }
}

//Find all the prime numbers between given range l and r;
//constraints : (l-r) <= 10^6,  r max can be 10^12.

//step 1. create a dummy array of r - l + 1 size and mark all as true.

//step 2. get all the primes until sqrt(r).

// step 3. for all prime number mark its multiples as false in l,r range on dummy.

//get all the prime.