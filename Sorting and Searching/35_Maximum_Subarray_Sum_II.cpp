/*
Question : 
input : array size <= 2e5, 1<=a<=b<=n , -1e9<= elements in array <=1e9
output : maximum sum of values in a contiguous subarray with length between a and b
intution : sliding window and calculating for ending at index i
soln : we calculate max ans for subarrays ending at every index i using sliding window of prefix sums(from i-a to i-b) as max subarray sum will be pf[index]-min(pf[] i-a to i-b) using multiset sliding window
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,a,b; cin>>n>>a>>b;
    ll v[n];
    for(int i=0;i<n;i++) cin>>v[i];
    multiset<ll> s; ll ans=-1e18;
    vector<ll> pf(n); pf[0]=v[0];
    for(int i=1;i<n;i++){
        pf[i]+=pf[i-1]+v[i];
    }
    for(int i=0;i<n;i++){
        if(i-a>=0) s.insert(pf[i-a]);
        if(i-a==-1) s.insert(0);
        if(i-b-1>=0) s.erase(s.find(pf[i-b-1]));
        if(i-b-1==-1) s.erase(s.find(0));
        if(s.size()>0) ans=max(ans,pf[i]-*(s.begin()));
    }
    cout<<ans<<"\n";
}

