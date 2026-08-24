/*
Question : 
input : n levels <=1e5, m teleporters <=2e5 (directed)
output : path using every teleporter exactly once from 1 to n, or IMPOSSIBLE
intution : eulerian path from 1 to n exists iff outdeg[1]-indeg[1]=1, indeg[n]-outdeg[n]=1, and all others indeg==outdeg
soln : check euler path conditions then find path using hierholzer algorithm
*/
#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<int> path;


void dfs(int i){
    while(adj[i].size()!=0){
        auto v=adj[i].back();
        adj[i].pop_back();
        dfs(v);
    }
    path.push_back(i);
}

int main(){
    int n,m; cin>>n>>m;
    adj.assign(n+1,vector<int>());
    vector<int> indeg(n+1),outdeg(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }
    bool ok=true;
    for(int i=1;i<=n;i++){
        if(i==1) {
            if(outdeg[i]-indeg[i]!=1) ok=false;
        }
        else if(i==n) {
            if(indeg[i]-outdeg[i]!=1) ok=false;
        }
        else {
            if(indeg[i]!=outdeg[i]) ok=false;
        }
    }
    dfs(1);
    reverse(path.begin(),path.end());
    if(!ok or path.size()!=m+1) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    }
}