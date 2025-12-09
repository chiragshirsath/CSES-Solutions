/*
Question : 
input : int n; n<=1e6
output : no of bit strings of length n
intution : combinatorics at each posn we have 2 choices
soln : 2^n
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007
int main(){
    ll n; cin>>n;
    ll ans=1;
    while(n--){
        ans*=2; ans%=mod;
    }
    cout<<ans<<"\n";
}