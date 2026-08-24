#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> parent,sz;
    DSU(int n){
        parent.assign(n+1,0);
        sz.assign(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int u, int v){
        u=find(u); v=find(v);
        if(u==v) return;

        if(sz[u]>sz[v]) swap(u,v);
        
        sz[v]+=sz[u];
        parent[u]=v;
    }
};

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({c,a,b});
    }
    sort(edges.begin(),edges.end());
    ll ans=0; int ct=1;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        if(dsu.find(edges[i][1])!=dsu.find(edges[i][2])){
            ct++;
            ans+=edges[i][0];
            dsu.Union(edges[i][1],edges[i][2]);
        }
    }
    if(ct==n) cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

}