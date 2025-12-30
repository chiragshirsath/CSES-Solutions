/*
Question : 
input : array size <= 2e5, integers in array -1e9<=x<=1e9
output :  count of number of subarrays where the sum of values is divisible by n
intution : related to sum of subarrays with sum k and sum%n=0 , (x1%n+x2%n+...)%n=0  so we modulo each element by n then want count of subarray with sum 0
soln : we want count of subarrays with sum 0 after taking elements%n
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    ll a[n]; map<ll,ll> mp; 
    mp[0]=1; ll sum=0,ans=0;
    for(int i=0;i<n;i++) {
        cin>>a[i]; a[i]%=n; a[i]=(a[i]+n)%n;
        sum+=a[i];
        sum%=n;
        ans+=mp[sum];
        mp[sum]++;
    }
    cout<<ans<<"\n";
}

