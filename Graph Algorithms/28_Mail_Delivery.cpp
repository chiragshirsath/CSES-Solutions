/*
Question : 
input : n crossings <=1e5, m streets <=2e5 (undirected)
output : route that traverses every street exactly once starting and ending at 1, or IMPOSSIBLE
intution : eulerian circuit exists iff all vertices have even degree and graph is connected
soln : check all degrees even, then find euler circuit using hierholzer algorithm with edge marking
*/
#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

vector<vector<pair<int,int>>> adj;
vector<int> path;
vector<int> used;

void dfs(int i){
    while(adj[i].size()!=0){
        auto [v,id]=adj[i].back();
        adj[i].pop_back();
        if(used[id]) continue;
        used[id]=1;
        dfs(v);
    }
    path.push_back(i);
}

int main(){
    int n,m; cin>>n>>m;
    adj.assign(n+1,vector<pair<int,int>>());
    int id=1;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back({b,id});
        adj[b].push_back({a,id});
        id++;
    }
    bool ok=true;
    for(int i=1;i<=n;i++){
        if(adj[i].size()%2!=0){
            ok=false; break;
        }
    }
    used.assign(m+1,0);
    if(ok) dfs(1);
    if(path.size()!=m+1) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    }
}