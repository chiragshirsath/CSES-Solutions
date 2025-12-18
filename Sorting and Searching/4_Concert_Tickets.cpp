/*
Question : 
input : n tickets m customers <=2e5, price of tickets and maximum price customer can pay <=1e9
Each customer gets ticket with the nearest possible price such that it does not exceed the maximum price 
output : for each customer price they pay
intution : brute force using set in nlogn
soln : maintain a set and the customer will pay the element before upperbound and it will be erased from set
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,m; cin>>n>>m;
    multiset<ll> s; ll x;
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        auto it1=s.upper_bound(x);
        if(it1!=s.begin()){
            it1--;
            cout<<*it1<<"\n";
            s.erase(it1);
        }
        else cout<<-1<<"\n";
    }
}

