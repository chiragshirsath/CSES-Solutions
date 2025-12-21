/*
Question : 
input : n numbers 1 to n exactly once n<=2e5
operation : On each round, you go through the array from left to right and collect as many numbers from 1 to n in increasing order as possible
output : the number of rounds
intution : we will get index in order for 1 to n then we can pick consecutive elements if their index is inc
soln : 
*/
 
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main(){
    ll n; cin>>n;
    ll a[n]; int idx[n];
    for(int i=0;i<n;i++) {
        cin>>a[i]; 
        idx[a[i]-1]=i;
    }
    int ans=1;
    for(int i=0;i<n-1;i++){
        if(idx[i]>idx[i+1]) ans++;
    }
    cout<<ans<<"\n";
}