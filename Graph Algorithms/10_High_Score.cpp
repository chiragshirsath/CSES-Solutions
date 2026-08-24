/*
Question : 
input : n nodes <=2500, m directed weighted edges <=5000
output : max score from node 1 to node n, -1 if infinite
intution : negate weights and find shortest path, if negative cycle exists on path to n then infinite
soln : bellman ford with negated weights, run n-1 relaxations then n more to detect negative cycles, if dist[n] still decreasing then -1
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,-c});
    }
    vector<ll> dist(n+1,1e18);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(auto &it : edges){
            int u=it[0]; int v=it[1]; ll wt=it[2];
            if(dist[u]!=1e18 and dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(auto &it : edges){
            int u=it[0]; int v=it[1]; ll wt=it[2];
            if(dist[u]!=1e18 and dist[u]+wt<dist[v]){
                dist[v]=-1e18;
            }
        }
    }
    if(dist[n]==-1e18) cout<<-1<<endl;
    else{
        cout<<-dist[n]<<endl;
    }
}