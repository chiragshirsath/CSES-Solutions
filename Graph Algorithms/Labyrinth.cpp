#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char dc[4]={'R','L','D','U'};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n,vector<char>(m));
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='A') {
                x=i; y=j;
            }
        }
    }
    queue<pair<int,int>> q;
    vector<vector<int>> track(n,vector<int>(m));
    q.push({x,y});
    a[x][y]='#';
    int ex=-1,ey=-1;
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        int x=top.first;
        int y=top.second;
        if(a[x][y]=='B'){
            ex=x; ey=y;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 and ny>=0 and nx<n and ny<m and a[nx][ny]!='#'){
                if(a[nx][ny]=='.') a[nx][ny]='#';
                track[nx][ny]=i;
                q.push({nx,ny});
            }
        }
    }
    
    if(ex==-1) cout<<"NO\n"; 
    else{
        cout<<"YES\n"; 
        vector<char> path;
        while(ex!=x or ey!=y){
            int curr=track[ex][ey];
            path.push_back(dc[curr]);
            ex-=dx[curr];
            ey-=dy[curr];
        }
        cout<<path.size()<<endl;
        for(int i=path.size()-1;i>=0;i--) cout<<path[i];
        cout<<endl;
    }
    
}