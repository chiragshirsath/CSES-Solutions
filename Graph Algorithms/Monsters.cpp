#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

char dc[4]={'D','U','L','R'};
int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> matrix(n,vector<char>(m));
    int a_i,a_j;
    queue<pair<int,int>> monsters;
    vector<vector<int>> monster_time(n,vector<int>(m,1e9));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]=='M') {
                monsters.push({i,j});
                monster_time[i][j]=0;
            }
            if(matrix[i][j]=='A'){
                a_i=i; a_j=j;
            }
        }
    }
    
    while(!monsters.empty()){
        int curr_i=monsters.front().first;
        int curr_j=monsters.front().second;
        monsters.pop();
        for(int k=0;k<4;k++){
            int new_i=curr_i+dx[k];
            int new_j=curr_j+dy[k];
            if(new_i>=0 and new_i<n and new_j>=0 and new_j<m and matrix[new_i][new_j]!='#' and monster_time[new_i][new_j]>1+monster_time[curr_i][curr_j]){
                monster_time[new_i][new_j]=1+monster_time[curr_i][curr_j];
                monsters.push({new_i,new_j});
            }
        }
    }

    queue<pair<int,int>> q;
    vector<vector<char>> path(n,vector<char>(m));
     vector<vector<int>> a_time(n,vector<int>(m,1e9));
    vector<char> ans;
    q.push({a_i,a_j});
    a_time[a_i][a_j]=0;
    while(!q.empty()){
        int curr_i=q.front().first;
        int curr_j=q.front().second;
        q.pop();
        if(curr_i==0 or curr_i==n-1 or curr_j==0 or curr_j==m-1){
            while(curr_i!=a_i or curr_j!=a_j){
                ans.push_back(path[curr_i][curr_j]);
                if(path[curr_i][curr_j]=='D'){
                    curr_i--;
                }
                else if(path[curr_i][curr_j]=='U'){
                    curr_i++;
                }
                else if(path[curr_i][curr_j]=='L'){
                    curr_j++;
                }
                else if(path[curr_i][curr_j]=='R'){
                    curr_j--;
                }
            }
            break;
        }
        for(int k=0;k<4;k++){
            int new_i=curr_i+dx[k];
            int new_j=curr_j+dy[k];
            if(new_i>=0 and new_i<n and new_j>=0 and new_j<m and matrix[new_i][new_j]!='#' and a_time[new_i][new_j]>1+a_time[curr_i][curr_j] and monster_time[new_i][new_j]>1+a_time[curr_i][curr_j]){
                a_time[new_i][new_j]=1+a_time[curr_i][curr_j];
                path[new_i][new_j]=dc[k];
                q.push({new_i,new_j});
            }
        }
    }
    if(ans.size()!=0 or a_i==0 or a_i==n-1 or a_j==0 or a_j==m-1){
        cout<<"YES\n"; 
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
        cout<<endl;
    }
    else cout<<"NO\n"; 
}