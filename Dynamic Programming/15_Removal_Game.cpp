/*
Question : 2 players take turns removing from either end of array, both play optimally, find max score of player 1
input : n <=5000, n integers
output : maximum score player 1 can get
intution : each player wants to maximize their own score, so relative advantage matters, at each turn pick the end that gives max advantage over opponent
soln : dp on intervals, dp[i][j] = max(score_you - score_opponent) for subarray i to j, pick left or right and subtract opponents best play

state : dp[i][j] = max advantage (your score - opponent score) for subarray a[i..j]
transition : dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1])
initialization : dp[i][i] = a[i]
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