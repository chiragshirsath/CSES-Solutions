#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> order,vis;
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
    for(int i=order.size()-1;i>=0;i--){
        if(vis[order[i]]==0) {
            if(a==-1) a=order[i]; 
            else{
                b=order[i]; break;
            }
            dfs2(order[i]);
        }
    }
    if(b!=-1){
        cout<<"NO\n"; 
        cout<<b<<" "<<a<<endl;
    }
    else cout<<"YES\n"; 

}