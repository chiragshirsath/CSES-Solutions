/*
Question : 
input : n numbers n<=2e5 , numbers<=1e9
output : length of longest sequence of unique integers
intution : check current length of longest sequence dynamically maintaing a start
soln : we have a left pointer which updates to the next index of a first appearance of element if it appears again and we take max of all valid sequences
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    int a[n]; map<int,int> mp; 
    for(int i=0;i<n;i++)  {
        cin>>a[i]; mp[a[i]]=-1;
    }
    int l=0; int ans=0;
    for(int i=0;i<n;i++){
        if(mp[a[i]]>=l) l=mp[a[i]]+1;
        mp[a[i]]=i;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
}