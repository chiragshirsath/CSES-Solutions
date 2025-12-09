/*
Question : 
input : int n; n<=1e9
output : number of trailing zeroes in n!
intution : trailing zeroes will be caused due to 2,5 , 5 will always be less
soln : min of no of 5 present in nos 1 to n 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    int ans=0;
    for(int i=5;i<=n;i*=5) ans+=n/i;
    cout<<ans<<"\n";
}