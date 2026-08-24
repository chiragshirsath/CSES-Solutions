/*
Question : 
input : n courses <=1e5, m requirements <=2e5 (directed edges)
output : valid order to complete all courses or IMPOSSIBLE
intution : topological sort, if topo order has all n nodes then valid else cycle exists
soln : kahns algorithm using indegree and bfs queue, if order size != n then IMPOSSIBLE
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m; cin>>n>>m;
    vector<int> indeg(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        indeg[b]++;
        adj[a].push_back(b);
    }
    vector<int> order;
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indeg[i]==0){
            q.push(i);
            order.push_back(i);
        }
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto &v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
                order.push_back(v);
            }
        }
    }
    if(order.size()==n){
        for(int i=0;i<n;i++) cout<<order[i]<<" ";
    }
    else cout<<"IMPOSSIBLE"<<endl;
}