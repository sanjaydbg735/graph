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
vector<int>color(N+1);
vector<int>graph[N+1];
vector<bool>visited(N+1);
void topologySort(int node,stack<int>&st){
    visited[node]=true;

    for(int child : graph[node]){
        if(!visited[child]){
            topologySort(child,st);
        }
    }
    st.push(node);
}


void solve(){
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
    }
    stack<int>st;
    for(int i=0;i<node;i++){
        if(!visited[i])topologySort(i,st);
    }
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
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