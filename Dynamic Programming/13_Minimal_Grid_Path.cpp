/*
Question : find the lexicographically smallest path from top-left to bottom-right in nxn grid moving only down or right
input : grid size n <=1000, nxn characters
output : the lexicographically smallest path string
intution : greedy bfs, at each step from all current positions pick the minimum char available in next possible cells
soln : maintain set of current positions, at each step find min char among all possible next moves (down/right), keep only positions that lead to that min char, repeat till we reach bottom-right
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
   int n; cin>>n;
   vector<string> s(n);
   for(int i=0;i<n;i++) cin>>s[i];
   string ans;
   ans+=s[0][0];
   vector<pair<int,int> > curr;
   curr.push_back({0,0});
   while(ans.size()!=2*n-1){

    vector<pair<int,int> >temp;
    char mn='z'+1; 
    for(int k=0;k<curr.size();k++){
        int i=curr[k].first,j=curr[k].second;
        if(i+1<n) mn=min(mn,s[i+1][j]);
        if(j+1<n) mn=min(mn,s[i][j+1]);
    }
    for(int k=0;k<curr.size();k++){
        int i=curr[k].first,j=curr[k].second;
        if(i+1<n and s[i+1][j]==mn) temp.push_back({i+1,j}); 
        if(j+1<n and s[i][j+1]==mn) temp.push_back({i,j+1});
    }
    sort(temp.begin(),temp.end());
    curr.clear();
    for(int k=0;k<temp.size();k++){
        if(curr.size()==0 or temp[k]!=curr.back()) curr.push_back(temp[k]);
    }
    int i=curr[0].first,j=curr[0].second;
    ans+=s[i][j];
    
   }
   cout<<ans;
}