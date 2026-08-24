/*
Question : 
input : n cities <=1e5, m roads <=2e5
output : min no of new roads needed to connect all cities and which roads to build
intution : find connected components using dsu, connect them by adding roads between component representatives
soln : union find to group connected cities, then connect all components by linking each to the first component
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N=100010;

int sz[N];
int par[N];

void make(int x){
    sz[x]=1;
    par[x]=x;
}

int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    par[y]=x;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        make(i);
    }
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        Union(x,y);
    }
    unordered_set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(find(i));
    }
    vector<pair<int,int>> ans;
    int top=-1;
    for(auto &e : s){
        if(top==-1) top=e;
        else ans.push_back({top,e});
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    
}