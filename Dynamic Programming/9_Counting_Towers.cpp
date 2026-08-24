/*
Question :  
input :  
output : 
intution : 
soln : 

state : 
transition : 
initialization :
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod=1e9+7;
static long long dp[1000010][2];

int main(){
    int t; cin>>t;
    dp[1][0]=1; dp[1][1]=1;
    for(int i=2;i<=1000000;i++){
        dp[i][0]=((2*dp[i-1][0])%mod+dp[i-1][1])%mod;
        dp[i][1]=(dp[i-1][0]+(4*dp[i-1][1])%mod)%mod;
    }
    while(t--){
        ll n; cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod<<"\n";
    }
}

// 4*|||   2*| |