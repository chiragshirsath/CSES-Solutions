/*
Question : 
input : n invtervals <= 2e5 , a,b<=1e9
output : minimum number of rooms that are needed to accommodate all customers such that two customer cannot stay in same room if they have common interval
intution : greedy brute force
soln : we can brute force geedily alloting a room to all possible customers using set then next room and so on
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;
const int INF=1000000001;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    multiset<pair<int,pair<int,int> > >s;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        s.insert({a,{b,i}});
    }
    int ans[n]; int r=1;
    while(!s.empty()){
        auto it=s.begin();
        while(it!=s.end()){
            ans[it->second.second]=r;
            int q=it->second.first;
            s.erase(it);
            it=s.upper_bound({q,{INF,INF}});
        }
        r++;
    }
    cout<<r-1<<"\n";
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
} 

// also can be bruteforce using maintaining available rooms and giving any room if there is none left then increasing the no of rooms