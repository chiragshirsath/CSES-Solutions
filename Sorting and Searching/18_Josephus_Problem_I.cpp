/*
Question : 
input : int n <= 2e5
game : n children in circle, every other child is removed
output : the removal order
intution : brute force using set maintaining children 1 to n
soln : we can use a set keeping 1 to n and current index according to which we can remove child and print no of child removed
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n; 
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    int k=2; bool ok=true;
    while(s.size()>1){
        auto imn=s.begin(); 
        auto imx=s.end(); imx--;
        if(ok) imn++;
        int mx=*imx,st=*imn;
        while(st<=mx){
            cout<<st<<" ";
            s.erase(st);
            st+=k;
        }
        if(st==mx+k) ok=true;
        else ok=false;
        k*=2;
    }
    if(s.size()){
        auto it=s.begin();
        cout<<*it<<"\n";
    }
} 