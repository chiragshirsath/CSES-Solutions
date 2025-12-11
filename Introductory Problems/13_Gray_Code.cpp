/*
Question : 
input : int n; n<=16
Grey code : two successive strings differ in exactly one bit
output : Grey code
intution : there may be a pattern, we take prev soln add 0 and 1 to end reverse and attach 
soln : further observation theres a pattern from lsb to rsb, last bit goes 01 10 01 10... last second 0011 1100 ... asd so on
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    vector<vector<int> > ans((1ll<<n),vector<int>(n));
    for(int j=n-1;j>=0;j--){
        int ct=0; bool sw=true;
        for(int i=0;i<(1ll<<n);i++){
            if(sw){
                if(ct<((1ll<<(n-j))/2)) ans[i][j]=0;
                else ans[i][j]=1;
            }
            else{
                if(ct<((1ll<<(n-j))/2)) ans[i][j]=1;
                else ans[i][j]=0;
            }
            ct++;
            if(ct==(1ll<<(n-j))){
                ct=0; sw = (!sw);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
}
