#include<bits/stdc++.h>
using namespace std;

class grph{

    public:
        unordered_map<int,list<int>> adj;

        void addEdge(int u,int v,bool isDirected){

            adj[u].push_back(v);

            if(!isDirected){
                adj[v].push_back(u);
            }
        }

        void print(){

            for(auto i:adj){

                cout<<i.first<<"->";

                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};

int main(){

    grph g;

    int n;
    cout<<"Enter number of edges:"<<endl;
    cin>>n;

    int m;
    cout<<"Enter number of nodes"<<endl;
    cin>>m;

    for(int i=0;i<n;i++){

        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,1);
    }

    g.print();
}