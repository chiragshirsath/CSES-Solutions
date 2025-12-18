/*
Question : 
input : q queries <=1000 int k 1 indexed position in string <=1e18
given : infinite string that consists of all positive integers in increasing order 12345678910111213141516171819202122232425...
output : what is the digit at position k
intution : we try to find the number at position k, as number are in chunks 1 digit 1-9 2 digit 10-189 n so on... 
soln: we know which digit numbers start when as there are 9 1-digit, 90 2-digit and so on... so we first find the number which k element is part of has how many digits then we track the number and find its desired digit
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll q; cin>>q;
    vector<ll> v; v.push_back(1);
    ll a=1,b=1,c=9;
    while(a<=1e18){
        a+=c*b;
        v.push_back(a);
        c*=10; b++;
    }
    while(q--){
        ll k; cin>>k; ll n=v.size();
        ll p=-1;
        for(ll i=0;i<n;i++)(v[i]<=k?p++:p=p);
        ll x=(k-v[p])/(p+1),y=(k-v[p])%(p+1);
        ll num=1;
        for(int i=0;i<p;i++) num*=10;
        num+=x;
        string s=to_string(num);
        cout<<s[y]<<"\n";
    }
}