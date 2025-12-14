/*
Question : 
input : int n; n<=1000
output : grid for each cell minimum number of moves the knight needs to do to reach the top-left corner
intution : reverse the question, min no of moves required by horse to reach a cell from corner
soln: this can be done using bfs
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool valid(int i,int j,int n){
    return i>=0 and j>=0 and i<n and j<n;
}

vector<pair<int,int> > movements={
 {1,2} , {1,-2} , {-1,2} , {-1,-2},
 {2,1} , {-2,1} , {2,-1} , {-2,-1}
};

int main(){
    ll n; cin>>n;
    vector<vector<ll> >ans(n,vector<ll>(n,-1));
    queue<pair<ll,ll> > q;
    ans[0][0]=0;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<ll,ll> top=q.front();
        q.pop();
        ll x=top.first;
        ll y=top.second;
        for(auto &movement : movements){
            ll xx=x+movement.first;
            ll yy=y+movement.second;
            if(valid(xx,yy,n) and ans[xx][yy]==-1){
                ans[xx][yy]=1+ans[x][y];
                q.push(make_pair(xx,yy));
            }
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout<<ans[i][j]<<" ";
        } cout<<"\n";
    }
}