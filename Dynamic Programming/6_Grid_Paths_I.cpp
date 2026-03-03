/*
Question : nxn grid with traps, can only move down or right
input : size of grid n<=1000
output : number of paths
intution : we can go to a cell from up or left so paths will be sum of path from up and left
soln : paths to go to a cell i j will be paths to go to cell i-1 j if its now a trap + paths to go to cell i j-1 if its not a trap

state : dp[i][j] for cell in row i and col j no of paths
transition : dp[i][j] = (i-1 j not a trap)?dp[i-1][j]:0 + (i j-1 not a trap)?dp[i][j-1]:0
initialization : till no trap found in row=1/col=1 then then 1 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod=1000000007;
static int dp[1010][1010];

int main(){
    ll n; cin>>n;
    char grid[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(grid[i][0]=='*') break;
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++){
        if(grid[0][i]=='*') break;
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++){
            if(grid[i][j]=='*') continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n-1][n-1]%mod<<endl;
    
}
