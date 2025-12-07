/*
Question : 
input : array of n integers
to do : make it increasing 
operation : increase any element by 1
output : minimum no of moves required 
intution : make next element equal to previous element if its small
soln : start from i=1 add max(0ll,a[i-1]-a[i]) to ans and update a[i]=max(a[i],a[i-1])
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<n;i++){
        ans+=max(0,a[i-1]-a[i]);
        a[i]=max(a[i],a[i-1]);
    }
    cout<<ans<<"\n";
}


