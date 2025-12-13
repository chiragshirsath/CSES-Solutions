/*
Question : 
input : int n; n<=16
output : minimum solution of tower of hanio
intution : recursion, we have 3 poles start middle end which keep on switching
soln: there are 2^n-1 steps, first the n-1th disk is moved from start to middle and them from middle to end
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(int n,int s,int m,int e){
    if(n==0) return;
    solve(n-1,s,e,m);
    cout<<s<<" "<<e<<endl;
    solve(n-1,m,s,e);
}

int main(){
    ll n; cin>>n;
    cout<<(1ll<<n)-1<<endl;
    solve(n,1,2,3);
}
