/*
Question : number of ordered distinct ways to create sum x using set of integers
input : no of coins n <=100 , sum to be created <=1e6 , set of n coins with ci<=1e6
output : no of ways
intution : counting by using coins one by one so no repetition of order
soln : if we can get to a sum with non zero ways then ways of sum+ci will be += ways of getting to sum, we will do this coin by coin to get distinct ordered ways

in 2d its like ways[sum][no of coins till j] = dp[sum-cj][no of coin till j](taking coin cj)+dp[sum][no of coin till j-1](not taking cj) ,for j 1 to n, sum 0 to x
can be done in 1d by going coin by coin in outer loop:

state : dp[current sum] which reperesents no of distinct ordered ways to create the current sum 
transition : dp[current sum + {coin values}] += dp[current sum]
initialization : dp[0]=1 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod=1e9+7;

static int dp[2000000];

int main(){
    ll n,x; cin>>n>>x;
    int coins[n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            if(dp[j]!=0) dp[j+coins[i]]+=dp[j];
            dp[j+coins[i]]%=mod;
        }
    }
    cout<<dp[x]%mod<<"\n";
}
