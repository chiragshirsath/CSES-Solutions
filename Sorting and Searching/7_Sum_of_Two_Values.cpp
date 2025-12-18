/*
Question : 
input : array size <= 2e5, integers and target sum <=1e9
output : any two positions of values which add up to target sum
intution : we find element using binary search and keep index stored in a map
soln : we have a map where we store index as value and if a , x-a both are in the map then print both index 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,x; cin>>n>>x;
    ll a[n]; multimap<ll,ll> idx;
    ll p=-1,q=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx.insert({a[i],i+1});
        if(a[i]==x/2){
            if(p==-1)p=i+1;
            else q=i+1;
        }
    }
    bool ok=true;
    for(auto &e: idx){
        if(x%2==0 and e.first==x/2) continue;
        auto it=idx.lower_bound(x-e.first);
        if(it!=idx.end() and it->first==x-e.first){
            cout<<e.second<<" "<<it->second<<"\n"; ok=false; break;
        }
    }
    if(q!=-1 and x%2==0){
        cout<<p<<" "<<q<<"\n"; ok=false;
    }
    if(ok) cout<<"IMPOSSIBLE\n";
}

