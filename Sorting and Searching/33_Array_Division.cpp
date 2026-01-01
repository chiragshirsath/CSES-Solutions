/*
Question : 
input : array size n <=2e5, k divisions <=n , elements in array <=1e9
operation : divide the array into k subarrays so that the maximum sum in a subarray is as small as possible
output : the maximum sum in a subarray in the optimal division
intution : binary search
soln : if a sum x requries p partition then any sum <x will require <=p partitions so we can binary search on sum n partitions
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool chk(ll mid,ll k,ll n,ll a[]){
    ll curr=0; ll p=0; 
    for(int i=0;i<n;i++){
        if(a[i]>mid) return false;
        curr+=a[i];
        if(curr>mid){
            p++; curr=a[i];
        }
    }
    if(p+1<=k) return true;
    return false;
}

int main(){
    ll n,k; cin>>n>>k;
    ll a[n]; ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i]; sum+=a[i];
    }
    ll hi=sum,lo=0,mid;
    while(hi-lo>1){
        mid=(hi+lo)/2;
        if(chk(mid,k,n,a)) hi=mid;
        else lo=mid;
    }
    if(chk(lo,k,n,a)) cout<<lo<<"\n";
    else cout<<hi<<"\n";
}