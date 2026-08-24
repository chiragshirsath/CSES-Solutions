#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> adj;
vector<int> vis;
vector<int> len;
vector<vector<int>> dp;

void dfs(int u){
    vis[u]=1;

    int v=adj[u];

    if(vis[v]==0){
        dfs(v);
        if(len[u]==0) len[u]=1+len[v];
    }
    else if(vis[v]==1){
        len[u]=1;
    }
    else if(vis[v]==2){
        len[u]=len[v]+1;
    }
    vis[u]=2;
}

int next(int x, int k){
    int res=x;
    for(int j=31;j>=0;j--){
        if(k&(1ll<<j)){
            res=dp[j][res];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q; cin>>n>>q;

    vis.assign(n+1,0);
    len.assign(n+1,0);
    adj.assign(n+1,0);
    dp.assign(32,vector<int>(n+1,0));

    for(int i=1;i<=n;i++) cin>>adj[i];
    
    for(int i=0;i<32;i++){
        for(int j=1;j<=n;j++){
            if(i==0) dp[i][j]=adj[j];
            else dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs(i);
    }

    for(int i=0;i<q;i++){
        int x,y; cin>>x>>y;
        if(next(x,len[x])==next(y,len[y])){
            int dist1=len[x]-len[y];
            int dist2=len[x]+(len[next(x,len[x])]-len[y]);
            if(dist1>=0 and next(x,dist1)==y) cout<<dist1<<endl;
            else if(dist2>=0 and next(x,dist2)==y) cout<<dist2<<endl;
            else cout<<-1<<endl;
            
        }
        else{
            cout<<-1<<endl;
        }
       
    } 
}

