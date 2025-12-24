/*
Question : 
input : n ranges n<=2e5, x,y<=1e9
output : line 1: if it contains some other range(1/0), line 2: if some other range contains it(1/0)
intution : sort with start ascending end descending and focus on ending , if staring is smaller and ending larger than it contains the current pair, if starting is greater and ending is smaller it is contained by current pair
soln : we can check using prefix max and suffix min in sorted order if any pair has less start and more end than current pair then it contains current pair and if more start than less end than current pair then current pair contains that pair
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;

struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b) const {
        if(a.first!=b.first) return a.first<b.first;
        return a.second>b.second;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<pair<int,int> >v(n);
    map<pair<int,int>,pair<int,int>,cmp > mp;
    for(int i=0;i<n;i++) {
        cin>>v[i].first>>v[i].second;
        mp[{v[i].first,v[i].second}];
    }
    int mx=0;
    for(auto &p : mp){
        if(mx>=p.first.second) mp[p.first].second=1;
        mx=max(mx,p.first.second);
    }    
    auto it=mp.end(); int mn=1e9+1; it--;
    while(1){
        if(mn<=it->first.second) it->second.first=1;
        mn=min(mn,it->first.second);
        if(it==mp.begin()) break;
        it--;
    }
    for(int i=0;i<n;i++) cout<<mp[v[i]].first<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<mp[v[i]].second<<" ";
    cout<<"\n";
} 

