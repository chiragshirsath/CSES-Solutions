#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin>>n>>q;
    vector<int> t(n);
    for(int i=0;i<n;i++) cin>>t[i];
    vector<vector<int>> dp(32,vector<int>(n+1));
    for(int i=0;i<32;i++){
        for(int j=0;j<n;j++){
            if(i==0) dp[i][j]=t[j]-1;
            else dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    for(int i=0;i<q;i++){
        int x,k; cin>>x>>k;
        x--;
        for(int j=31;j>=0;j--){
            if(k&(1ll<<j)){
                x=dp[j][x];
            }
        }
        cout<<x+1<<"\n";
    } 
}
