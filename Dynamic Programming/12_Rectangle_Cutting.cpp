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

static long long dp[501][501];

int main(){
    ll a,b; cin>>a>>b;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j) dp[i][j]=0;
            if(i==1) dp[i][j]=j-1;
            if(j==1) dp[i][j]=i-1;
        }
    }
    dp[0][0]=0;
    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){
            dp[i][j]=min(dp[i][j],1+dp[i-1][j]+j-1);
            dp[i][j]=min(dp[i][j],1+dp[i][j-1]+i-1);
            for(int k=1;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
            }
            for(int k=1;k<=i-1;k++){
                dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
            }
        }
    }
    cout<<dp[a][b];
}