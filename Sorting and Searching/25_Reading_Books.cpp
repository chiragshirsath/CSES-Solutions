/*
Question : n books <=2e5, time to read a book <=1e9
output : min total time required by two people to read all books, they cannot read a book at the same time
intution : max time and distributing greedily to which has less time
soln : if max time >= sum of all other books ans will be 2*max time else ans will be total sum of all times the distribution will be greedy starting from largest time book added to person with less time.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll a[n]; 
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll s1=0,s2=0,s=0;
    for(int i=n-1;i>=0;i--){
        if(s1>s2) s2+=a[i];
        else s1+=a[i];
        if(i!=n-1) s+=a[i];
    }
    if(s<a[n-1]) cout<<2*a[n-1]<<"\n";
    else cout<<s1+s2<<"\n";
} 

