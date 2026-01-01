/*
Question : 
input : n movies <= 2e5, start and end time of movies a,b <=1e9 , k members <=n
output : maximum number of movies k members can watch entirely
intution : similar to movie festival but optimally taking choices
soln : similar to movie festival 1(job scheduling) we sort then the for indiex 1<=i<=n curr movie is watched by a member who finished watching a movie most recently and so on to get max ans 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,k; cin>>n>>k;
    vector<pair<int,int> >v(n);
    for(int i=0;i<n;i++) cin>>v[i].second>>v[i].first;
    sort(v.begin(),v.end());
    ll ans=0; multiset<ll> s;
    for(int i=0;i<n;i++){
        if(s.size()>0){
            auto it=s.upper_bound(v[i].second); 
            if(it==s.begin() and s.size()<k) {
                s.insert(v[i].first); ans++;
            }
            else if(it!=s.begin()){
                it--; ans++;
                s.erase(it);
                s.insert(v[i].first);
            }
        }
        else {
            s.insert(v[i].first); ans++;
        }
    }
    cout<<ans<<"\n";
}

