/*
Question : 
input : a 48 char string with directions
operation : in a 7x7 grid start from upper left to reach lower left
output : total possible paths after filling ? in the given string
intution : brute force recursion
soln: while doing the backtracking dfs like recursion to avoid tle we need to add pruning if we reach the target before 48 moves or we cant go forward/backward in same direction but we can go in both perpendicular directions as this will split grid in 2 parts and we will never visit 1 part 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ans=0;

bool vis[9][9];

void solve(int i, int j,int k,string &s){
    if(k==48){
        ans+=(i==7 and j==1);
        return;
    }
    if(i==7 and j==1) return;
    
    if((vis[i][j+1]) and (vis[i][j-1])){
        if(vis[i-1][j]==0 and vis[i+1][j]==0) return;
    }
    if((vis[i+1][j]) and (vis[i-1][j])){
        if(vis[i][j-1]==0 and vis[i][j+1]==0) return;
    }
    
    if((s[k]=='D' or s[k]=='?') and vis[i+1][j]==0){
        vis[i+1][j]=1;
        solve(i+1,j,k+1,s);
        vis[i+1][j]=0;
    }
    if((s[k]=='U' or s[k]=='?') and vis[i-1][j]==0){
        vis[i-1][j]=1;
        solve(i-1,j,k+1,s);
        vis[i-1][j]=0;
    }
    if((s[k]=='R' or s[k]=='?') and vis[i][j+1]==0){
        vis[i][j+1]=1;
        solve(i,j+1,k+1,s);
        vis[i][j+1]=0;
    }
    if((s[k] =='L' or s[k]=='?') and vis[i][j-1]==0){
        vis[i][j-1]=1;
        solve(i,j-1,k+1,s);
        vis[i][j-1]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    vis[1][1]=1;
    for(int i=0;i<9;i++){
        vis[i][0]=1; vis[0][i]=1;
        vis[8][i]=1; vis[i][8]=1;
    }
   solve(1,1,0,s); 
   cout<<ans<<"\n";
}
