/*
Question : minimum no of operations to convert string s to string t
input : string s,t with length <=5000
output : minimum edit distance (insert/delete/replace)
intution : classic dp, if chars match no cost else take min of insert delete replace
soln : 2d dp where dp[i][j] is min edits to convert first i chars of s to first j chars of t

state : dp[i][j] = min operations to convert s[0..i-1] to t[0..j-1]
transition : dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+(s[i-1]!=t[j-1]))
initialization : dp[i][0]=i (delete all), dp[0][j]=j (insert all)
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static long long dp[5010][5010];

int main(){
    string s,t; cin>>s>>t;
    int n=s.size(); int m=t.size();
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int j=0; j<=m; j++) dp[0][j] = j;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(s[i-1]!=t[j-1])});
        }
    }
    cout<<dp[n][m];
    
}