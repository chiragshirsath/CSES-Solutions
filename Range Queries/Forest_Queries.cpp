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