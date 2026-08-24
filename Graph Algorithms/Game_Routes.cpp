#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

int main(){
    int n,m; cin>>n>>m;
    vector<int> indeg(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        indeg[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indeg[i]==0) q.push(i);
    }
    vector<ll> ways(n+1,0);
    vector<int> par(n+1);
    ways[1]=1;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto &v : adj[u]){
            indeg[v]--;
            ways[v]+=ways[u]%mod;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    cout<<ways[n]%mod<<endl;
}