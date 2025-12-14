/*
Question : 
input : int n; n<=100
mex grid : each square has the smallest nonnegative integer that does not appear to the left on the same row or above on the same column
output : mex grid
intution : must be a pattern or n is small to brute force
soln: we can just brute force in n^3
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    int ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vector<int> a(200);
            for(int p=0;p<i;p++){
                a[ans[p][j]]=1;
            }
            for (int q = 0; q < j; ++q){
                a[ans[i][q]]=1;
            }
            for (int k = 0; k < 200; ++k){
                if(a[k]==0){
                    ans[i][j]=k; break;
                }
            }
        } 
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        } cout<<"\n";
    }
}
