/*
Question : create a sum x using minimum no of integers from given set
input : no of coins n <= 100, sum x <=1e6 , n distinct coins ci<=1e6 
output : minimum no of coins to make sum x
intution : as n is small to create a sum x we choose minimum of coins req to make x-ci + 1
soln : min no of coins to make a sum x, we take minimum of min no of coins to make sum-all possible coins

state : dp[sum] minimum no of coins required to make sum
transition : dp[sum]=1+min(dp[sum-{coins}]) if dp[sum-coin]!=1e9(not possible)
initialization : dp[0]=0 dp[{coins}]=1 others=1e9
*/


#include <bits/stdc++.h>
using namespace std;

static int dp[1000010];

using ll = long long;

int main(){
    ll n,x; cin>>n>>x;
    int coins[n];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++) {
        cin>>coins[i];
        dp[coins[i]]=1;
    }
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0 and dp[i-coins[j]]!=-1) dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
    }
    if(dp[x]>1e6) cout<<-1<<"\n";
    else cout<<dp[x]<<"\n";
}
