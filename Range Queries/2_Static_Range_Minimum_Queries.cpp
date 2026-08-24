/*
Question : 
input : array size n <=2e5, q queries <=2e5
output : for each query minimum element in range [a,b]
intution : sparse table for range min queries, precompute min for all power of 2 ranges
soln : build sparse table dp[i][j] = min of 2^i elements starting at j, query by splitting range into 2 overlapping power of 2 blocks
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    vector<vector<int>> dp(32,vector<int>(n+1));
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=0;i<32;i++){
        for(int j=1;j+(1ll<<i)-1<=n;j++){
            if(i==0) dp[i][j]=v[j];
            else dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1ll<<(i-1))]);
        }
    }
    for(int i=0;i<q;i++){
        int a,b; cin>>a>>b;
        int len=b-a+1; int ans=1e9;
        for(int j=31;j>=0;j--){
            if((1ll<<j)&len){
                ans=min(ans,dp[j][a]);
                a+=(1ll<<j);
                len-=(1ll<<j);
            }
        }
        cout<<ans<<endl;
    }
}