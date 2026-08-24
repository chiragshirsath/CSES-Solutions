/*
Question : 
input : n nodes <=500, m edges <=n*(n-1)/2, q queries <=1e5
output : for each query shortest distance between 2 nodes or -1
intution : n is small so floyd warshall works in O(n^3)
soln : floyd warshall to precompute all pairs shortest paths then answer queries in O(1)
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m,q; cin>>n>>m>>q;
    vector<vector<ll>> matrix(n+1,vector<ll>(n+1,-1));
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        matrix[a][b]=(matrix[a][b]==-1?c:min(matrix[a][b],c));
        matrix[b][a]=(matrix[a][b]==-1?c:min(matrix[a][b],c));
    }
    for(int i=1;i<=n;i++) matrix[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i][k]==-1 or matrix[k][j]==-1) continue;
                if(matrix[i][j]==-1) matrix[i][j]=matrix[i][k]+matrix[k][j];
                else{
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int x,y; cin>>x>>y;
        cout<<matrix[x][y]<<endl;
    }
}