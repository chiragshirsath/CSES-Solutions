/*
Question : 
input : n computers <=1e5, m connections <=2e5
output : minimum no of computers on route from 1 to n, or IMPOSSIBLE
intution : shortest path in unweighted graph is bfs
soln : bfs from node 1, store parent of each node, if n is reached backtrack parents to get path
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
    q.push(1);
    vis[1]=-1;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        if(top==n){
            break;
        }
        for(auto &e :  adj[top]){
            if(vis[e]) continue;
            q.push(e);
            vis[e]=top;
        }
    }
    if(vis[n]){
        vector<int> path;
        int curr=n;
        while(curr!=1){
            path.push_back(curr);
            curr=vis[curr];
        }
        cout<<path.size()+1<<endl;
        cout<<1<<" ";
        for(int i=path.size()-1;i>=0;i--) cout<<path[i]<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
}