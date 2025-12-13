/*
Question : 
input : 8x8 chars representing chess board with free/reserved square
output : possible ways to place 8 queens such that no queens atack each other
intution : variation of n queens problem, solved using recursion and backtracking
soln: same as n queens with a extra check for a[i][j] should be free
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

char a[8][8];
int col[8];
int diag1[16];
int diag2[16];

int solve(int n){
    if(n==8) return 1;
    int ans=0;
    for(int i=0;i<8;i++){
        if(a[n][i]=='.' and col[i]==0 and diag1[n+i]==0 and diag2[8+n-i]==0){
            col[i]=1; diag1[n+i]=1; diag2[8+n-i]=1;
            ans+=solve(n+1);
            col[i]=0; diag1[n+i]=0; diag2[8+n-i]=0;
        }
    }
    return ans;
}

int main(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>a[i][j];
        }
    }
    cout<<solve(0)<<"\n";
}
