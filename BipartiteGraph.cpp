#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int   long long int
#define ll long long

// Bipartite graph only for Directed and acyclic graph

const int MOD = 1e9 + 7;
const int mod = 1e9+7;
const int INF = 1e18+7ll;
const int N = 2*1e5+2;

vector<int> parent(N+1);
vector<int>color(N+1);
vector<int>graph[N+1];
vector<bool>visited(N+1);

bool bipartiteDFS(int node){
    if(color[node]==-1)color[node]=1;

    for(auto child: graph[node]){
        if(color[child]==-1){
            color[child]=1-color[node];
            if(!bipartiteDFS(child)){
                return false;
            }
        }
        else if(color[child]==color[node])return false;
    }
    return true;
}


void solve(){
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<=node;i++)color[i]=-1;
    //if root node is one
    for(int i=1;i<=node;i++){
        if(color[i]==-1){
           if(!bipartiteDFS(i)){
               cout<<"Graph is not bipartite\n";
               return;
           }
        }
    }
    cout<<"Graph is bipartite\n";
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
