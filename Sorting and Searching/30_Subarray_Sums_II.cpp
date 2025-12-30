/*
Question : 
input : no of integers n <= 2e5, target sum,value of integers -1e9<=x,n<=1e9
output : count of number of subarrays having sum x
intution : calculating counf of subarrays ending at index i for all i
soln : if the prefix sum till index i is p then to find no of subarrays with sum x ending at i we need to know the count of indices with prefix sum p-x which can be done storing pf count in map 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,x; cin>>n>>x;
    ll a[n]; map<ll,ll> mp; 
    ll ans=0; ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
        if(sum==x) ans++;
        ans+=mp[sum-x];
        mp[sum]++;
    }
    cout<<ans<<"\n";
}

