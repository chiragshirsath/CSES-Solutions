/*
Question : 
input : nxn grid <=1000, q queries <=2e5, cells are trees(*) or empty(.)
output : for each query count trees in rectangle [x1,y1] to [x2,y2]
intution : 2d prefix sum on grid
soln : build 2d prefix sum, answer each query using inclusion-exclusion: pf[x2][y2] - pf[x2][y1-1] - pf[x1-1][y2] + pf[x1-1][y1-1]
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,q; cin>>n>>q;
    vector<vector<int>> v(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char t; cin>>t;
            v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1]+(t=='*');
        }
    }
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        cout<<v[x2][y2]-v[x2][y1-1]-v[x1-1][y2]+v[x1-1][y1-1]<<endl;
    }
} 