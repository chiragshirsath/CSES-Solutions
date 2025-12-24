/*
Question : 
input : n ranges n<=2e5, x,y<=1e9
output : line 1: count of ranges it contains , line 2: count of some other range contains that it
intution : sort with start ascending end descending and focus on ending , if staring is smaller and ending larger than it contains the current pair, if starting is greater and ending is smaller it is contained by current pair
soln : we can count using ordered prefix set and suffix set in sorted order storing in set and finding count of ends less than or greater than current end
*/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    ordered_multiset<int> mx;
    for(auto &p : mp){
        mp[p.first].second=mx.size()-mx.order_of_key(p.first.second);
        mx.insert(p.first.second);
    }    
    auto it=mp.end(); it--;
    ordered_multiset<int> mn;
    while(1){
        it->second.first=mn.order_of_key(it->first.second+1);
        mn.insert(it->first.second);
        if(it==mp.begin()) break;
        it--;
    }
    for(int i=0;i<n;i++) cout<<mp[v[i]].first<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<mp[v[i]].second<<" ";
    cout<<"\n";
} 

