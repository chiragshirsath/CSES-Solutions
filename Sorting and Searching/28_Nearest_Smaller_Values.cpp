/*
Question : 
input : array size <= 2e5, integers in array <=1e9
output : for each array position the nearest position to its left having a smaller value
intution : using a set/stack storing value index pairs
soln :  when we go left to right and have a new value at curr index tham for all integers > curr value the ans is curr index so we erase/clear elements bigger than current value and search for element before lowerbound for ans
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll a[n]; 
    for(int i=0;i<n;i++) cin>>a[i];
    set<pair<ll,ll> > s;
    for(int i=0;i<n;i++){
        auto ans=s.lower_bound({a[i],0});
        if(ans==s.begin()) cout<<0<<" ";
        else{
            ans--; cout<<ans->second<<" ";
        }
        while(s.size()){
            auto it=s.end(); it--;
            if(it->first>=a[i]) s.erase(it);
            else break;
        }
        s.insert({a[i],i+1});
    }
}

