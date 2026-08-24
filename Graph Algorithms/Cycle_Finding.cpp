#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    vector<ll> dist(n+1,0);
    vector<int> parent(n+1,-1);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(auto &it : edges){
            int u=it[0]; int v=it[1]; ll wt=it[2];
            if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
                parent[v]=u;
            }
        }
    }
    int pv=-1;
    for(auto &it : edges){
        int u=it[0]; int v=it[1]; ll wt=it[2];
        if(dist[u]+wt<dist[v]){
            parent[v]=u;
            pv=v; break;
        }
    }
    if(pv==-1) cout<<"NO\n"; 
    else{
        cout<<"YES\n"; 
        vector<int> vis(n+1);
        int curr=pv;
        while(vis[curr]==0){
            vis[curr]=1;
            curr=parent[curr];
        }
        int start=curr;
        vector<int> cycle;
        cycle.push_back(curr);
        curr=parent[curr];
        while(curr!=start){
            cycle.push_back(curr);
            curr=parent[curr];
        }
        cycle.push_back(curr);
        for(int i=cycle.size()-1;i>=0;i--) cout<<cycle[i]<<" ";
    }
}