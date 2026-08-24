/*
Question : 
input : grid of n rows m cols <=1000, cells are floor(.) or wall(#)
output : count the no of rooms (connected components of floor cells)
intution : simple bfs/dfs flood fill, mark visited cells and count components
soln : iterate over grid, when we find an unvisited floor cell do bfs to mark all connected floor cells and increment count
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                ans++;
                queue<pair<int,int>>q;
                q.push({i,j});
                int dx[4]={1,-1,0,0};
                int dy[4]={0,0,-1,1};
                while(!q.empty()){
                    auto top=q.front();
                    q.pop();
                    int x=top.first;
                    int y=top.second;
                    for(int i=0;i<4;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]=='.'){
                            a[nx][ny]='#';
                            q.push({nx,ny});
                        }
                    }
                    
                }
            }
        }
    }
    cout<<ans<<endl;
    

}