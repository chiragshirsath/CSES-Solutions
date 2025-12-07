/*
Question : 
input : int n; n<=1e6
operation : till n!=1 -> if n&1 n=(n*3+1); else n/=2; 
output : all values of n till 1
indirectly we know its always possible with these operations to reach 1
intution : if n odd n becomes even, when n even we do/=2 so operations to make n==1 should be less
*/

// theres no other better solution so lets try brute force

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    while(n!=1) {
        cout<<n<<" ";
        ((n&1)?n=(n*3)+1:n/=2);
    } cout<<1<<"\n";
}

// it worked and turns out this problem is a part of Collatz Conjecture which has no proof yet :(
