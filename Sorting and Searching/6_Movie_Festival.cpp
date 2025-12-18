/*
Question : 
input : n movies <= 2e5, start and end time of movies a,b <=1e9 
output : maximum number of movies you can watch entirely
intution : similar to job scheduling greedy problem
soln : sort according to end time and then same as job scheduling select movies with as less ending time possible and keep doing it for max ans
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    vector<pair<int,int> >v(n);
    for(int i=0;i<n;i++) cin>>v[i].second>>v[i].first;
    sort(v.begin(),v.end());
    ll ans=0, curr=0; 
    for(int i=0;i<n;i++){
        if(v[i].second>=curr){
            ans++; curr=v[i].first;
        }
    }
    cout<<ans<<"\n";
}

