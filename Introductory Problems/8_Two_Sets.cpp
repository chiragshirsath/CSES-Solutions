/*
Question : 
input : int n; n<=1e6
operation :  divide 1,2,....n into two sets of equal sum
output : if it is possible then both the sets else no
intution : the total sum is n*(n+1)/2 so we need 2 sets of sum n*(n+1)/4 so n*(n+1)%4 should be 0 else no
soln : if n*n+1 %4 == 0 then ans is possible, if n is even the set 1 will be all odd nos till n/2 and all even nos from n/2 to n and when n is odd set 1 will be 1,2, first (n-3)/2 even nos and other odd nos till n
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    if(n*(n+1)%4!=0) cout<<"NO\n";
    else{
        cout<<"YES\n";
        if(n&1){
            cout<<n/2+1<<"\n";
            cout<<1<<" "<<2<<" ";
            for(int i=1;i<=(n-3)/4;i++) cout<<3+2*i<<" ";
            for(int i=1;i<=(n-3)/4;i++) cout<<n-(n-3)/2-1+2*i<<" ";
            cout<<"\n";
            cout<<n/2<<"\n";
            cout<<3<<" ";
            for(int i=1;i<=(n-3)/4;i++) cout<<2+2*i<<" ";
            for(int i=1;i<=(n-3)/4;i++) cout<<n-(n-3)/2+2*i<<" ";
            cout<<"\n";
        }
        else{
            cout<<n/2<<"\n";
            for(int i=1;i<=n/4;i++) cout<<-1+2*i<<" ";
            for(int i=1;i<=n/4;i++) cout<<n/2+2*i<<" ";
            cout<<"\n";
            cout<<n/2<<"\n";
            for(int i=1;i<=n/4;i++) cout<<2*i<<" ";
            for(int i=1;i<=n/4;i++) cout<<n/2-1+2*i<<" ";
            cout<<"\n";
        }
    }
}