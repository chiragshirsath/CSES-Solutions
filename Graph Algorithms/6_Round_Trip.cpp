/*
Question : 
input : n cities <=1e5, m roads <=2e5, undirected
output : find a round trip (cycle) of atleast 3 cities, or IMPOSSIBLE
intution : dfs cycle detection in undirected graph, track parent to avoid trivial back-edge
soln : dfs with parent tracking, when we visit an already visited node we found a cycle, backtrack using parent array to extract it
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N=100010;

vector<vector<int>> adj;
vector<int> vis,par;
int cst=-1;
int cen=-1;

bool dfs(int v, int p){
    vis[v]=1; par[v]=p;
    for(auto &e : adj[v]){
        if(e==p) continue;
        if(vis[e]){
            cst=e;
            cen=v;
            return true;
        }
        if(dfs(e,v)) return true;
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    par.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(i,-1)) break;
        
    }
    if(cst==-1) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> ans;
        ans.push_back(cst);
        while(cst!=cen){
            ans.push_back(cen);
            cen=par[cen];
        }
        ans.push_back(cst);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    }
}