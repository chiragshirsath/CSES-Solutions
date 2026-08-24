/*
Question : 2xn grid tower using 1x1 and 1x2 tiles (can combine vertically too)
input : t testcases <=100, n <=1e6
output : no of ways to fill the 2xn tower
intution : at each level the 2 columns can be either split(2 separate tiles) or combined(1 wide tile), and transition depends on prev state
soln : maintain 2 states split and combined, from split we can go to 4 splits or 1 combined, from combined we can go to 1 split or 4 combined so we precompute for all n

state : dp[i][0] = no of ways when row i has 2 split tiles, dp[i][1] = no of ways when row i has 1 combined tile
transition : dp[i][0] = 2*dp[i-1][0] + dp[i-1][1], dp[i][1] = dp[i-1][0] + 4*dp[i-1][1]
initialization : dp[1][0]=1, dp[1][1]=1
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