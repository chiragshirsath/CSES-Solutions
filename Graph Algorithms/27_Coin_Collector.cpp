/*
Question : 
input : n rooms <=1e5 with coins, m directed tunnels <=2e5
output : max coins collectible starting from any room
intution : condense sccs into single nodes (sum their coins), then longest path on dag
soln : kosaraju for sccs, build condensation dag with summed coin values, dp on dag to find max coins
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
    vector<int> coins(n+1);
    for(int i=1;i<=n;i++) cin>>coins[i];
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs1(i);
    }
    vis.assign(n+1,0);
    num.assign(n+1,0);
    for(int i=order.size()-1;i>=0;i--){
        if(vis[order[i]]==0) {
            dfs2(order[i]);
            no++;
        }
    }
    long long ans=0;
    vector<long long> val(n+1);
    for(int i=1;i<=n;i++){
        val[num[i]]+=coins[i];
    }
    int sn=no-1;
    vector<set<int>> sadj(sn+1);
    for(int u=1;u<=n;u++){
        for(int v : adj[u]){
            int su=num[u];
            int sv=num[v];
            if(su!=sv){
                if(sadj[su].find(sv)==sadj[su].end()){
                    sadj[su].insert(sv);
                }
            }
        }
    }
    vector<long long> dp(sn+1);
    for(int i=1;i<=sn;i++) dp[i]=val[i];
    for(int u=1;u<=sn;u++){
        for(auto v : sadj[u]){
            dp[v]=max(dp[v],dp[u]+val[v]);
        }
    }
    for(int i=1;i<=sn;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}