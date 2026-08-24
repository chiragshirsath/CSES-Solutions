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

long long dp[5001][5001];
long long vis[5001][5001];
long long a[5001];
long long n;

long long solve(int i, int j){
    if(i>j) return 0;

    if(vis[i][j]) return dp[i][j];

    long long mx=0;
    mx=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));

    vis[i][j]=1;

    return dp[i][j]=mx;
}

int main(){
    cin>>n;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(dp));
    long long sum=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; sum+=a[i];
    }
    long long diff=solve(1,n);
    cout<<(sum+diff)/2;
}