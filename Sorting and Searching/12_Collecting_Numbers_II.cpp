/*
Question : 
input : n numbers 1 to n exactly once and m swaps  n,m<=2e5  
operation : On each round, you go through the array from left to right and collect as many numbers from 1 to n in increasing order as possible after each swap 
output : the number of rounds after each swap
intution : we will get index in order for 1 to n then we can pick consecutive elements if their index is inc after swap we just check around the swaps
soln : we remove starting ans and then after swap check around swapped indices and update ans after each query
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,m; cin>>n>>m;
    ll a[n]; int idx[n];
    for(int i=0;i<n;i++) {
        cin>>a[i]; 
        idx[a[i]-1]=i;
    }
    int ans=1;
    for(int i=0;i<n-1;i++){
        if(idx[i]>idx[i+1]) ans++;
    }
    for(int i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        x--; y--;
        ll p=a[x]-1,q=a[y]-1; 
        ll t=min(p,q); q=max(p,q); p=t;
        ll c1=0;
        if(p-1>=0) if(idx[p-1]>idx[p]) c1++;
        if(p+1<n) if(idx[p]>idx[p+1]) c1++;
        if(q-1>p) if(idx[q-1]>idx[q]) c1++;
        if(q+1<n) if(idx[q]>idx[q+1]) c1++;
        swap(idx[p],idx[q]);
        swap(a[x],a[y]);
        ll c2=0;
        if(p-1>=0) if(idx[p-1]>idx[p]) c2++;
        if(p+1<n) if(idx[p]>idx[p+1]) c2++;
        if(q-1>p) if(idx[q-1]>idx[q]) c2++;
        if(q+1<n) if(idx[q]>idx[q+1]) c2++;
        ans+=(c2-c1);
        cout<<ans<<endl;
    }   
}