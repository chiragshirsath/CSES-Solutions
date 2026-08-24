/*
Question : 
input : n cities <=1e5, m roads added one by one <=2e5
output : after each road: no of components and size of largest component
intution : dsu with size tracking, each union decreases components and may update max size
soln : union find with path compression and union by size, track component count and max component size
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;

        if (sz[u] > sz[v]) swap(u, v);
        
        sz[v] += sz[u];
        parent[u] = v;
    }
};

int main(){
    int n,m; cin>>n>>m;
    DSU dsu(n);
    int components=n, maxcomponent=1;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        if(dsu.find(u)!=dsu.find(v)){
            components--;
            dsu.Union(u,v);
        }
        maxcomponent=max(maxcomponent,dsu.sz[dsu.find(v)]);
        cout<<components<<" "<<maxcomponent<<endl;
    }
}