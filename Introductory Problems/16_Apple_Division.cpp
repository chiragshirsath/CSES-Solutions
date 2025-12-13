/*
Question : 
input : int n; n<=20 array with apple weights of size n wih a[i]<=1e9
output : minimum weight difference of group of apples after spliiting apples in two groups
intution : n is small we can generate all subsets and brute force minimum
soln: at each index we choose to take the apple in grp 1 or not and weight of grp 2 at the end is total weight - wt of grp 1, we take min of all possible subsets
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll tw=0;
ll solve(int i,vector<int> &a,ll wt){
    int n=a.size();
    if(i==n){
        return abs(wt-(tw-wt));
    }
    return min(solve(i+1,a,wt+a[i]),solve(i+1,a,wt));
}

int main(){
    ll n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        tw+=a[i];
    }
    cout<<solve(0,a,0)<<"\n";
}


// this can be done iteratively using bits to make subsets
// this can also be solved using dp 