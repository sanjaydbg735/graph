#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int   long long int
#define ll long long


const int MOD = 1e9 + 7;
const int mod = 1e9+7;
const int INF = 1e18+7ll;
const int N = 2*1e5+2;

vector<int> parent(N+1);
vector<int>dfs_visited(N+1);
vector<int>graph[N+1];
vector<bool>visited(N+1);

bool IsCycleDirectedGraph(int node){
    visited[node]=true;
    dfs_visited[node]=true;

    for(auto child: graph[node]){
        if(!visited[child]){
            if(IsCycleDirectedGraph(child))return true;
        }
        else if(dfs_visited[child]) {
            return true;
        }
    }
    dfs_visited[node]=false;
    return false;

}

void solve(){
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);// for Directed graph
        
    }
    for(int i=0;i<=node;i++)visited[i]=0,dfs_visited[i]=0;
    //if root node is one
    for(int i=1;i<=node;i++){
        if(!visited[i]){
           if(IsCycleDirectedGraph(i)){
               cout<<"Cycle is present in a graph\n";
               return;
           }
        }
    }
    cout<<"Cycle is not present in graph\n";
}


signed main(){
    IOS // fast inpcout output
    // int t=1;
    int t;cin>>t;
    // sieve(N);
    while(t--){
        solve();
    }
    return 0;
}