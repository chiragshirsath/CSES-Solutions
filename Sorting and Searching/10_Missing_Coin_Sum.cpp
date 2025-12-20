/*
Question : 
input : no of coins n <=2e5, value of coins <= 1e9
output : smallest sum you cannot create using a subset of the coins
intution : brute force untill we dont find a no from 1
soln : lets say current sum is curr if next coin is <=curr we can make all sums till a[i]+curr else we need to check if a[i] is equal to curr+1 as it cant be made otherwise
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    ll a[n]; 
    for(int i=0;i<n;i++) cin>>a[i]; 
    sort(a,a+n);
    ll curr=0;
    for(int i=0;i<n;i++){
        if(a[i]>curr and a[i]!=curr+1){
            cout<<curr+1<<"\n"; return 0;
        }
        curr+=a[i];
    }
    cout<<curr+1<<"\n";
}

