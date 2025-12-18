/*
Question : 
input : int n; n<=2e5 and n integers <=1e9
output : number of distinct values
intution : can be done using sorting or even stl
soln : sort the array and count no of times consecutive elements are unequal+1
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ans=1;
    for(int i=1;i<n;i++)
        if(a[i]!=a[i-1]) ans++;
    cout<<ans<<"\n";
}

// other ways -> stl : set/map or using unique() (Shifts the unique consecutive elements to the beginning of the container 
//                     Returns an iterator pointing to the element just after the last unique element)