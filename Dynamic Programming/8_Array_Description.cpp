/*
Question : array that can contain values 1 to m and diff btw 2 adjacent values is atmost 1 has some missing values denoted by 0
input :  array size n<=1e5, upperbound value for array elements m<=100 , 0<= n integers <=m
output : number of arrays formed after filling missing values
intution : going element one by one and calculate ans for array of size 0<=i<=n ending with 1<=x<=m
soln : for each position if its 0 we try all values 1 to m if not we use the given value, dp counts ways for subarrays ending with each value

state : dp[i][x] no of valid arrays of size i+1 ending with value x
transition : dp[i][x] = dp[i-1][x] + dp[i-1][x-1] + dp[i-1][x+1] (if arr[i]==0 or arr[i]==x)
initialization : dp[0][arr[0]]=1 if arr[0]!=0, else dp[0][1..m]=1
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

static long long dp[100010][110];

int main(){
 ll n,m; cin>>n>>m;
 long long arr[n];
 for(int i=0;i<n;i++) cin>>arr[i];
 memset(dp,0,sizeof(dp));
 if(arr[0]==0){
    for(int j=1;j<=m;j++) dp[0][j]=1;
 }
 else {
    dp[0][arr[0]]=1;
 }
 for(int i=1;i<n;i++){
    if(arr[i]==0){
        if(arr[i-1]==0){
            for(int j=1;j<=m;j++){
                dp[i][j]+=dp[i-1][j]%mod;
                if(j>1) dp[i][j]+=dp[i-1][j-1]%mod;
                if(j<m) dp[i][j]+=dp[i-1][j+1]%mod;
                dp[i][j]%=mod;
            }
        }
        else{
            dp[i][arr[i-1]]+=dp[i-1][arr[i-1]]%mod;
            if(arr[i-1]>1) dp[i][arr[i-1]]+=dp[i-1][arr[i-1]-1]%mod;
            if(arr[i-1]<m) dp[i][arr[i-1]]+=dp[i-1][arr[i-1]+1]%mod;
            dp[i][arr[i-1]]%=mod;

            dp[i][arr[i-1]+1]+=dp[i-1][arr[i-1]]%mod;
            dp[i][arr[i-1]+1]%=mod;

            dp[i][arr[i-1]-1]+=dp[i-1][arr[i-1]]%mod;
            dp[i][arr[i-1]-1]%=mod;
        }
    }
    else{
        dp[i][arr[i]]+=dp[i-1][arr[i]]%mod;
        if(arr[i]>1) dp[i][arr[i]]+=dp[i-1][arr[i]-1]%mod;
        if(arr[i]<m) dp[i][arr[i]]+=dp[i-1][arr[i]+1]%mod;
        dp[i][arr[i]]%=mod;
    }
 }
 if(arr[n-1]==0){
    int ans=0;
    for(int j=1;j<=m;j++) {
        ans+=dp[n-1][j]; ans%=mod;
    }
    cout<<ans%mod<<"\n";
 }
 else cout<<dp[n-1][arr[n-1]]%mod<<"\n";
}

