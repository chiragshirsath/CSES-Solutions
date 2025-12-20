/*
Question : 
input : array size <= 2e5, -1e9<= elements in array <=1e9
output : maximum subarray sum
intution : kadanes algo
soln : maintain the subarray sum , when its get negative then reset it to 0 and take max over all sum
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    ll sum=0,ans=-1e18;
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        sum+=x; ans=max(sum,ans);
        if(sum<0) sum=0;
    }
    cout<<ans<<"\n";
}

