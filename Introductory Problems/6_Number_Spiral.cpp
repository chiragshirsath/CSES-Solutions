/*
Question : 
input : t testcases t<=1e5, int y,x row and col y,x<=1e9
output : number in row y and col x in number spiral
intution : in nxn number spiral last row/col has n^2 and ans should be mostly o(1)
soln : we take mx=max(y,x) now for mx*mx grid we are checking in min(y,x) row/col depending on even or odd row/col we can track the number in the cell (y,x)
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll t; cin>>t;
    while(t--){
        ll y,x; cin>>y>>x;
        if(x<y){
            if(y&1){
                cout<<(y-1)*(y-1)+x<<'\n';
            }
            else{
                cout<<y*y-(x-1)<<"\n";
            }
        }
        else{
            if(x&1){
                cout<<x*x-(y-1)<<"\n";
            }
            else{
                cout<<(x-1)*(x-1)+y<<"\n";
            }
        }
    }
}
