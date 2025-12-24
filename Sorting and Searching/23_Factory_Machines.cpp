/*
Question : n machines<=2e5, t products<=1e9, array of time req to make a product using each machine <=1e9
output : minimum time needed to make t products
intution : binary search
soln : if we can make t products int time x then we can make in any time > x so we binary search on this predicate function to find min
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool chk(ll mid,ll t,ll n,ll a[]){
    ll p=0; 
    for(int i=0;i<n;i++) {
        p+=mid/a[i];
        if(p>=t) return true;
    }
    return false;
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,t; cin>>n>>t;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll hi=1e18,lo=0,mid;
    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(chk(mid,t,n,a)) hi=mid;
        else lo=mid;
    }
    if(chk(lo,t,n,a)) cout<<lo<<"\n";
    else cout<<hi<<"\n";
} 
