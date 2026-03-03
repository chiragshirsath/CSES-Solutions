/*
Question : number of distinct ways to create sum x using set of integers
input : no of coins n <=100 , sum to be created <=1e6 , set of n coins with ci<=1e6
output : no of ways
intution : couting no of ways to make a sum from 0 with adding ways of sum to sum+all choices of coins
soln : no of ways to make a sum is sum of no of ways to make sum-possible values of coins, starting to calculate this from 0 to x

state : dp[current sum] which reperesents no of ways to create the current sum 
transition : dp[current sum + {coin values}] += dp[current sum]
initialization : dp[0]=1 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod=1000000007;
static int dp[2000000];

int main(){
    ll n,x; cin>>n>>x;
    int coins[n];
    for(int i=0;i<n;i++) cin>>coins[i];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<x;i++){
        for(int j=0;j<n;j++){
            dp[i+coins[j]]+=dp[i];
            dp[i+coins[j]]%=mod;
        }
    }
    cout<<dp[x]%mod<<endl;
}
