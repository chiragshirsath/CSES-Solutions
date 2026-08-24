/*
Question : 
input : n cities <=1e5, m flights <=2e5, directed
output : find a round trip (directed cycle) or IMPOSSIBLE
intution : dfs with 3 states: unvisited(0), in-stack(1), done(2), back edge to in-stack node means cycle
soln : dfs coloring, when we find edge to a node with state 1 (in current path) we found a cycle, backtrack parent to extract it
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<int>> adj;
vector<int> vis,par;
int st=-1;
int en=-1;

bool dfs(int u){
    vis[u]=1;
    for(auto &v : adj[u]){
        if(vis[v]==0){
            par[v]=u;
            if(dfs(v)) return true; 
        }
        else if(vis[v]==1){
            st=v; en=u;
            return true;
        }
        else continue;
    }
    vis[u]=2;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.assign(n+1,vector<int>());
    vis.assign(n+1,0);
    par.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0) {
            if(dfs(i)) break;
        }
    }
    if(st==-1) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> ans;
        int curr=en;
        ans.push_back(st);
        while(curr!=st){
            ans.push_back(curr);
            curr=par[curr];
        }
        ans.push_back(st);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    }
}