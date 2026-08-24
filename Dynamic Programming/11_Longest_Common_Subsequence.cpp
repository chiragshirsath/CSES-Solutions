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

static long long dp[1010][1010];

int main(){
    ll n,m; cin>>n>>m;
    int a[n]; int b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
    vector<int> ans;
    int curri=n,currj=m;
    while(dp[curri][currj]!=0){
        if(dp[curri-1][currj]==dp[curri][currj]) {
            curri--; 
        }
        else if(dp[curri][currj-1]==dp[curri][currj]){
            currj--;
        }
        else{
            ans.push_back(a[curri-1]); curri--; currj--;
        }
    }
 
    cout<<dp[n][m]<<"\n";
    int k=ans.size();
    for(int i=k-1;i>=0; i--) cout<<ans[i]<<" "; 
    cout<<"\n";
    
}