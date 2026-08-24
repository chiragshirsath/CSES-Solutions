#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>> dist(n+1,vector<ll>(2,1e18));
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> pq;
    dist[1][0]=0;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto [curr,node,state]=pq.top();
        pq.pop();
        if(curr>dist[node][state]) continue;
        for(auto &it : adj[node]){
            int v=it.first;
            ll wt=it.second;
            if(state==0){
                if(curr+wt<dist[v][0]){
                    dist[v][0]=curr+wt;
                    pq.push({curr+wt,v,0});
                }
                if(curr+wt/2<dist[v][1]){
                    dist[v][1]=curr+wt/2;
                    pq.push({curr+wt/2,v,1});
                }
            }
            else{
                if(curr+wt<dist[v][1]){
                    dist[v][1]=curr+wt;
                    pq.push({curr+wt,v,1});
                }
            }
        }
    }
    cout<<min(dist[n][0],dist[n][1])<<endl;
}