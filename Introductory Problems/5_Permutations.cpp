/*
Question : 
input : int n;
operation : create a permutation with no adjacent elements with diff 1
output : desired permutation
intution : keep even together and odd together as they have diff 2
soln : print .... 5 3 1 .... 6 4 2
edge cases : n=2,3 no solution
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    if(n==2 or n==3) cout<<"NO SOLUTION"<<"\n";
    else{
        for(int i=(n&1?n:n-1);i>0;i-=2) cout<<i<<" ";
        for(int i=(n&1?n-1:n);i>0;i-=2) cout<<i<<" ";
        cout<<"\n";
    }
}

// other soltions may exist