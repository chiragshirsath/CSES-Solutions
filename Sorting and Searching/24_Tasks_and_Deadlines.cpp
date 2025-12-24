/*
Question : n tasks<=2e5, duration and deadline a,d<=1e6
reward : d-f (f->finishing time) f starts from 0
output : maximum reward after processing each task
intution : greedy, deadlines wont matter
soln : sort tasks according to duration and remove reward as if duration a>b and if we keep a before b then swap so finally becomes b before a then change in reward is a-b>0
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    ll ans=0; ll f=0;
    for(int i=0;i<n;i++){
        f+=v[i].first;
        ans+=v[i].second-f;
    }
    cout<<ans<<"\n";
} 
