#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod=1e9+7;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
    }
    vector<ll> ways(n+1);
    vector<ll> dist(n+1,1e18);
    vector<ll> min_len(n+1,1e18);
    vector<ll> max_len(n+1,0);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,1});
    ways[1]=1;
    min_len[1]=0;
    dist[1]=0;
    while(!pq.empty()){
        auto[curr,u]=pq.top();
        pq.pop();
        if(curr>dist[u]) continue;

        for(auto &it : adj[u]){
            auto [v,wt]=it;
            if(curr+wt==dist[v]) {
                ways[v]=(ways[v]+ways[u])%mod;
                min_len[v]=min(min_len[v],1+min_len[u]);
                max_len[v]=max(max_len[v],1+max_len[u]);
            }
            if(dist[u]!=1e18 and curr+wt<dist[v]){
                ways[v]=ways[u];
                min_len[v]=1+min_len[u];
                max_len[v]=1+max_len[u];
                dist[v]=curr+wt;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<min_len[n]<<" "<<max_len[n];
}