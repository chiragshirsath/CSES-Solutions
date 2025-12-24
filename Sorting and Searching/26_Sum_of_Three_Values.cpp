/*
Question : 
input : array size <= 5000, integers and target sum <=1e9
output : any three positions of values which add up to target sum
intution : we find element using binary search and keep value,index stored in a set
soln : we go n^2 through all 2 pairs and find if the third element which add ups to x is present in remaing array using binary search on set with value,index 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,x; cin>>n>>x;
    ll a[n]; set<pair<ll,ll> > idx;
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx.insert({a[i],i+1});
    }
    bool ok=true;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll sum=a[i]+a[j];
            auto it=idx.lower_bound({x-sum,j+2});
            if(it==idx.end() or sum+it->first!=x) continue;
            cout<<i+1<<" "<<j+1<<" "<<it->second<<"\n";
            ok=false;
            break;
        }
        if(!ok) break;
    }
    if(ok) cout<<"IMPOSSIBLE\n";
}

