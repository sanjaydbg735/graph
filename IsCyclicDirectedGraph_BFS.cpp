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

// root node is zero
bool IsCyclicDirectedGraphBFS(int NumberOfNodes){

    InDegreeOfDirectedGraph(NumberOfNodes); // calculating ingree
    queue<int>que;
    for(int i=0;i<NumberOfNodes;i++){
        if(inDegree[i]==0){ // if indegree of any node then push in queue
            que.push(i);
        }
    }
    int acyclicNodes=0;
    while(que.size()){
        int node=que.front();
        que.pop();
        acyclicNodes++;

        for(auto child:graph[node]){
            inDegree[child]--;
            if(inDegree[child]==0)que.push(child);
        }
    }

    if(acyclicNodes==NumberOfNodes)return false;
    else return true;
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        graph[u].pb(v);
    }
   bool Cycle = IsCyclicDirectedGraphBFS(n);

   if(Cycle)cout<<"Cycle is present in Directed graph\n";
   else cout<<"Cycle is not present in Directed graph\n";
   
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