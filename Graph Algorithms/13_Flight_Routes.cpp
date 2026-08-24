/*
Question : 
input : n cities <=1e5, m flights <=2e5, k <=10
output : k shortest route lengths from 1 to n
intution : modified dijkstra maintaining k shortest distances per node using max heap
soln : for each node keep a max heap of size k with shortest distances, push into pq if we can improve any of k distances
*/
#include<bits/stdc++.h> 
using namespace std;

using ll = long long;

int main(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<priority_queue<ll>> dist(n+1);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dist[1].push(0);
    pq.push({0,1});
    while(!pq.empty()){
        auto [curr,node] = pq.top();
        pq.pop();
        if(dist[node].size()==k and curr>dist[node].top()) continue;
        for(auto &it : adj[node]){
            auto [v,wt] = it;
            if(dist[v].size()<k){
                dist[v].push(curr+wt);
                pq.push({curr+wt,v});
            }
            else if(dist[v].top()>curr+wt){
                dist[v].push(curr+wt);
                pq.push({curr+wt,v});
                dist[v].pop();
            }
        }
    }
    vector<ll> ans;
    while(!dist[n].empty()){
        ans.push_back(dist[n].top());
        dist[n].pop();
    }
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";

}