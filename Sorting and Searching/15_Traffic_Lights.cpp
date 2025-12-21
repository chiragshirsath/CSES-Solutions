/*
Question : 
input : street length x <=1e9, n lights <=2e5, position of lights <x
operation : at each iteration we set a traffic light at position 
output : ongest passage without traffic lights after each addition
intution : brute force using 2 sets 1 will have all lengths 1 will have all numbers
soln : 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x,n; cin>>x>>n;
    set<int> s; s.insert(0); s.insert(x);
    multiset<int> ms; ms.insert(x); 
    for(int i=0;i<n;i++){
        ll p; cin>>p;
        s.insert(p); 
        auto it=s.find(p);
        auto it1=it,it2=it;
        it1--; it2++;
        int k=*it2-*it1;
        auto er=ms.find(k);
        ms.erase(er);
        ms.insert(*it2-*it); ms.insert(*it-*it1);
        auto ans=ms.end();
        ans--;
        cout<<*ans<<" ";
    } cout<<"\n";
}

// this problem can also be solved using dsu starting from end