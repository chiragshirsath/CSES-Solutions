/*
Question : 
input : n numbers n<=2e5 , numbers<=1e9
output : the number of subarrays where each element is distinct
intution : counting valid subarrays ending at index i 
soln : we keep last position as the max valid index and add no of subarrays ending at inex i for 0<=i<n 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    int a[n]; map<int,int> mp,f; 
    for(int i=0;i<n;i++)  {
        cin>>a[i]; mp[a[i]]=-1;
    }
    int l=0; ll ans=0;
    for(int i=0;i<n;i++){
        if(mp[a[i]]>=l) l=mp[a[i]]+1;
        mp[a[i]]=i;
        ans+=i-l+1;
    }
    cout<<ans<<"\n";
}