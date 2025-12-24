/*
Question : 
input : n numbers n<=2e5 , numbers<=1e9
output : the number of subsequences where each element is distinct
intution : combinatorics
soln : choice of choosing a number is (freq+1) so ans will be product of all numbers freq+1
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;

int main(){
    ll n; cin>>n;
    map<int,int> mp; 
    for(int i=0;i<n;i++)  {
        int x; cin>>x;
        mp[x]++;
    }
    ll ans=1;
    for (auto &p : mp){
        ans*=(p.second+1);
        ans%=mod;
    }
    cout<<ans-1<<"\n";
} 