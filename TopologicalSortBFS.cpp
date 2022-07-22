#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int   long long int
#define ll long long
#define pb push_back

const int MOD = 1e9 + 7;
const int mod = 1e9+7;
const int INF = 1e18+7ll;
const int N = 2*1e5+2;

vector<int> inDegree(N+1);
vector<int>graph[N+1];

void InDegreeOfDirectedGraph(int NumberOfNodes){
    for(int node=0;node<NumberOfNodes;node++){
        for(auto child:graph[node]){
            inDegree[child]++;
        }
    }
}
vector<int> topologicalSortBFS(int NumberOfNodes){

    InDegreeOfDirectedGraph(NumberOfNodes); // calculating ingree

    vector<int>sortedNode;
    queue<int>que;
    for(int i=0;i<NumberOfNodes;i++){
        if(inDegree[i]==0){
            que.push(i);
        }
    }

    while(que.size()){
        int node=que.front();
        que.pop();
        sortedNode.push_back(node);

        for(auto child:graph[node]){
            inDegree[child]--;
            if(inDegree[child]==0)que.push(child);
        }
    }
    
    return sortedNode;
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].pb(v);
    }
   vector<int>topoSort = topologicalSortBFS(n);

   for(auto nodes:topoSort)cout<<nodes<<" ";
    cout<<endl;
   
}

signed main(){
    IOS // fast inpcout output
    int t=1;
    // int t;cin>>t;
    // sieve(N);
    while(t--){
        solve();
    }
    return 0;
}