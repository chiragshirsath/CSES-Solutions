/*
Question : 
input : n planets <=2e5 each pointing to one planet (functional graph)
output : for each planet how many steps to return to it (cycle length for cycle nodes, tail+cycle for tail nodes)
intution : dfs with states: unvisited, in-progress, done. when we find cycle mark all cycle nodes with cycle length, tail nodes get 1+next
soln : dfs coloring, detect cycles and assign cycle length to cycle nodes, for non-cycle nodes len = 1 + len[next]
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> adj;
vector<int> vis;
vector<int> len;

void dfs(int u){
    vis[u]=1;

    int v=adj[u];

    if(vis[v]==0){
        dfs(v);
        if(len[u]==0) len[u]=1+len[v];
    }
    else if(vis[v]==1){
        int cycle=1;
        int curr=adj[v];
        while(curr!=v){
            cycle++;
            curr=adj[curr];
        }

        len[v]=cycle;
        curr=adj[v];
        while(curr!=v){
            len[curr]=cycle;
            curr=adj[curr];
        }
    }
    else if(vis[v]==2){
        len[u]=len[v]+1;
    }
    vis[u]=2;
}

int main(){
    ll n; cin>>n;
    
    vis.assign(n+1,0);
    len.assign(n+1,0);
    adj.assign(n+1,0);
    for(int i=1;i<=n;i++) {
        cin>>adj[i];    
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs(i);
        cout<<len[i]<<" ";
    }
    
}