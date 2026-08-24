#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
    vector<ll> dist(n+1,-1e18);
    vector<int> par(n+1);
    dist[1]=0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto &v : adj[u]){
            indeg[v]--;
            if(1+dist[u]>dist[v]) par[v]=u;
            dist[v]=max(dist[v],1+dist[u]);
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    if(dist[n]==-1e18) cout<<"IMPOSSIBLE"<<endl;
    else {
        // for(int i=1;i<=n;i++) cout<<par[i]<<" ";
        vector<int> ans;
        int curr=n;
        while(curr!=1){
            ans.push_back(curr);
            curr=par[curr];
        }
        ans.push_back(1);
        int k=ans.size();
        cout<<k<<endl;
        for(int i=k-1;i>=0;i--) cout<<ans[i]<<" ";
    }
}