/*
Question :  
input :  
output : 
intution : 
soln : 

state : 
transition : 
initialization :
*/



#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod=1e9+7;
int dp[1000000];

int main(){
   int n; cin>>n;
   int sum=n*(n+1)/2;
   if(sum&1) cout<<0<<"\n";
   else{
    sum/=2;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=0;j--){
            if(dp[j]!=0) dp[j+i]+=dp[j];
            dp[j+i]%=mod;
        }
    }
    cout<<((dp[sum]%mod)*(500000004ll%mod))%mod<<"\n";
   }
}

