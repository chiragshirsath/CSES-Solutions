/*
Question : 
input : n customers <=2e5 their time of arrival and leaving  a,b<= 1e9
output : the maximum number of customers at any time
intution : something like difference array but as a,b is large but n is small so using mapping
soln : we consider arrival as +1 and leaving as -1 then we want the maxima of sum which will be max people present at current time
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        mp[x]++; mp[y]--;
    }
    ll ans=0,curr=0;
    for(auto &e : mp){
        curr+=e.second;
        ans=max(ans,curr);
    }
    cout<<ans<<endl;
}

