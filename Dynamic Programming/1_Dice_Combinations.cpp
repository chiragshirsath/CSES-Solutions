/*
Question : number of ways we can construct sum n by throwing a dice one or more times
input : int n <=1e16 , the sum to be made
output : no of ways
intution : couting no of ways to make a sum from 0 with all 6 choices
soln : no of ways to make a sum is sum of no of ways to make sum-possible values of dice throw,  using this from 0 till n to get the ans

state : dp[current sum] which reperesents no of ways to create the current sum using dice 
transition : dp[current sum + {dice values}] += dp[current sum]
initialization : dp[0]=1 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod=1000000007;
static int dp[1000010];

int main(){
    ll n; cin>>n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=6;j++){
            dp[i+j]+=dp[i];
            dp[i+j]%=mod;
        }
    }
    cout<<dp[n]%mod<<endl;
}
