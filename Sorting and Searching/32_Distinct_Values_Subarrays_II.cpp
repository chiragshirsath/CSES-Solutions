/*
Question : 
input : n numbers n<=2e5 , numbers<=1e9, k<=n
output : the number of subarrays that have at most k distinct values
intution : counting valid subarrays ending at index i from end mainting 2 pointers and map containing current no of unique elements in interval i to j
soln : we maintain current count of unique elements and a window between i and j , wee keep adding elements to map and reduce j until j is 0 or map has more than k unique elements after which we add count of valid subarrays for i and reduce i
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,k; cin>>n>>k;
    int a[n]; 
    for(int i=0;i<n;i++)  {
        cin>>a[i]; 
    }
    ll ans=0;
    map<int,int> mp;
    ll i=n,j=n;
    while(i>0 or j>0){
        if(mp.size()>k){
            i--;
            ans+=i-j; 
            mp[a[i]]--;
            if(mp[a[i]]==0) mp.erase(a[i]);
        }
        else if(j==0){
            i--;
            ans+=i-j+1; 
            mp[a[i]]--;
            if(mp[a[i]]==0) mp.erase(a[i]);
        }
        else {
            j--;
            mp[a[j]]++; 
        }
    }
    cout<<ans<<"\n";
}