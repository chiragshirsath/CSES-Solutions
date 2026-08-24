/*
Question : 
input : n pupils <=1e5, m friendships <=2e5
output : divide into 2 teams such that no 2 friends in same team, or IMPOSSIBLE
intution : this is graph 2-coloring / bipartite check using bfs
soln : bfs and assign alternating colors 1 and 2, if any adjacent nodes have same color its IMPOSSIBLE
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N=100010;


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,0);
    queue<int> q;
    bool ans=true;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto &e :  adj[top]){
                if(vis[e]==vis[top]){
                    ans=false; break;
                }
                if(vis[e]) continue;
                q.push(e);
                vis[e]=((vis[top]==1)?2:1);
            }
            if(!ans) break;
        }
        if(!ans) break;
    }
    
    if(!ans) cout<<"IMPOSSIBLE"<<endl;
    else for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
}