#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<ll> v,t;

void build(int idx, int l, int r){
    if(l==r){
        t[idx]=v[l];
        return;
    }
    int mid=(l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    t[idx]=min(t[2*idx],t[2*idx+1]);
}

void update(int idx, int l, int r, int pos, int val){
    if(l>pos or r<pos) return;
    if(l==r){
        v[l]=val;
        t[idx]=v[l];
        return;
    }
    int mid=(l+r)/2;
    update(idx*2,l,mid,pos,val);
    update(idx*2+1,mid+1,r,pos,val);
    t[idx]=min(t[2*idx],t[2*idx+1]);
}

ll query(int idx, int l, int r, int a, int b){
    if(r<a or l>b) return 1e9;
    if(l>=a and r<=b) return t[idx];
    int mid=(l+r)/2;
    
    return min(query(idx*2,l,mid,a,b),query(idx*2+1,mid+1,r,a,b));
    
}


int main(){
    int q; cin>>n>>q;
    v.assign(n+1,0);
    t.assign(4*(n+1),1e9);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int op; cin>>op;
        if(op==1){
            int k,u; cin>>k>>u;
            update(1,1,n,k,u);
        }
        else{
            int a,b; cin>>a>>b;
            cout<<query(1,1,n,a,b)<<endl;
        }
    }
    
}