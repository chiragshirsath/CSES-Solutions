/*
Question : 
input : n nodes <=1e5, m directed weighted edges <=2e5, weights <=1e9
output : shortest distance from node 1 to all other nodes
intution : standard dijkstra with priority queue
soln : dijkstras algorithm using min heap, relax edges and update distances
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<ll> dist(n+1,1e18);
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto curr=pq.top();
        int curr_edge=curr.second;
        ll distance=curr.first;
        pq.pop();
        if(distance>dist[curr_edge]) continue;
        for(auto &p : adj[curr_edge]){
            int adj_edge=p.first;
            int wt=p.second;
            if(distance+wt<dist[adj_edge]){
                dist[adj_edge]=distance+wt;
                pq.push({dist[adj_edge],adj_edge});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}