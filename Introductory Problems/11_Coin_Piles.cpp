/*
Question : 
input : t testcases t<=1e5, a,b no of coins in each pile a,b<=1e9
operation : remove 2 coins from 1 pile and 1 coin from other
output : is it possible to make both piles empty
intution : making both piles equal, we can do removal 2,1 or 1,2 and their combinations so if a pile is large try to make it eqaual and in equal combinations of 2 1 and 1 2 are multiple of 3
soln : we make both piles equal by doing operation on bigger pile (diff of orignal piles) no of times then check if the no is divisible by 3
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll t; cin>>t;
    while(t--){
        ll a,b; cin>>a>>b;
        int k=abs(a-b);
        if(a>b){
            a-=2*k; b-=k;
        }
        else{
            a-=k; b-=2*k;
        }
        if(a>=0 and a%3==0) cout<<"YES\n";
        else cout<<"NO\n";
   }
}

// another soln i came across :
// as we remove 2 coins from 1 coin so a+b%3!=0 its never possible to make them empty 
// when (a+b)%3==0 it will be always possible to make both empty if the smaller pile is sufficient i.e 2*min(a,b)>=max(a,b)
// this soln will also work as there are all possible combinations possible when a+b is divisible by three and smaller pile is sufficiently large
