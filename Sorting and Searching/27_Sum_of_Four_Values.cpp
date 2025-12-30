/*
Question : 
input : array size <= 1000, integers and target sum <=1e9
output : any four positions of values which add up to target sum
intution : need less than n^3, need to optimise something n^2/n^2logn
soln : we have sum of all pairs and pairs indices stored in a set them we use like meet in middle delete all sum of subarrays to the left and find req sum in remaining pairs sum to the right which are present in set
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,x; cin>>n>>x;
    ll a[n]; 
    for(int i=0;i<n;i++) cin>>a[i];
    multiset<pair<ll,pair<ll,ll> > > s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s.insert({a[i]+a[j],{i,j}});
        }
    }
    bool ok=true;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s.erase({a[i]+a[j],{i,j}});
        }
        for(int j=i-1;j>=0;j--){
            auto it=s.lower_bound({x-(a[i]+a[j]),{0,0}});
            if(it==s.end() or it->first!=x-(a[i]+a[j]) ) continue;
            else{
                cout<<i+1<<" "<<j+1<<" "<<it->second.first+1<<" "<<it->second.second+1<<"\n";
                ok=false; break;
            }
        }
        if(!ok) break;
    }
    if(ok) cout<<"IMPOSSIBLE\n";
}

