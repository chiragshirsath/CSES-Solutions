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
    int n,m; cin>>m>>n;
    adj.assign(2*n+2,vector<int>());
    radj.assign(2*n+2,vector<int>());
    for(int i=0;i<m;i++){
        char x,y; int a,b; cin>>x>>a>>y>>b;
        int u=(x=='+')?2*a:(2*a+1);
        int v=(y=='+')?2*b:(2*b+1);
        int nu=u^1;
        int nv=v^1;
        adj[nu].push_back(v);
        radj[v].push_back(nu);

        adj[nv].push_back(u);
        radj[u].push_back(nv);
    }
    vis.assign(2*n+2,0);
    for(int i=2;i<=2*n+1;i++){
        if(vis[i]==0) dfs1(i);
    }
    vis.assign(2*n+2,0);
    num.assign(2*n+2,0);
    for(int i=order.size()-1;i>=0;i--){
        if(vis[order[i]]==0) {
            dfs2(order[i]);
            no++;
        }
    }
    vector<char> ans(n+1);
    bool poss=true;
    for(int i=1;i<=n;i++){
        if(num[2*i]==num[2*i+1]){
            poss=false;
            break;
        }
        if(num[2*i]>num[2*i+1]) ans[i]='+';
        else ans[i]='-';
    }
    if(!poss) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }
}