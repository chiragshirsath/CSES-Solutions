/*
Question : 
input : n planets <=1e5, m teleporters <=2e5 (directed)
output : no of kingdoms (scc count) and kingdom assignment for each planet
intution : strongly connected components are the kingdoms
soln : kosaraju algorithm - dfs on original for order, dfs on reverse to assign scc numbers
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int no=1;
vector<int> order,vis,num;
vector<vector<int>> adj,radj;

void dfs1(int i){
    if(vis[i]) return;
    vis[i]=true;
    
    for(auto &c : adj[i]){
        if(vis[c]) continue;
        dfs1(c);
    }
    order.push_back(i);
}

void dfs2(int i){
    if(vis[i]) return;
    vis[i]=true;
    num[i]=no;
    for(auto &c : radj[i]){
        if(vis[c]) continue;
        dfs2(c);
    }
}

int main(){
    int n,m; cin>>n>>m;
    adj.assign(n+1,vector<int>());
    radj.assign(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs1(i);
    }
    int a=-1,b=-1;
    vis.assign(n+1,0);
    num.assign(n+1,0);
    for(int i=order.size()-1;i>=0;i--){
        if(vis[order[i]]==0) {
            dfs2(order[i]);
            no++;
        }
    }
    cout<<no-1<<endl;
    for(int i=1;i<=n;i++) cout<<num[i]<<" ";
    

}