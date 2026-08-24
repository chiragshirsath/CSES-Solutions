/*
Question : 
input : n levels <=1e5, m teleporters <=2e5 (directed dag)
output : no of paths from level 1 to level n modulo 1e9+7
intution : dag so topo sort + dp, ways to reach v = sum of ways to reach all u with edge u->v
soln : kahns topo sort, accumulate ways along topo order
*/
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