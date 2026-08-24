/*
Question : count no of ways to divide numbers 1 to n into 2 sets with equal sum
input : n <=500
output : no of ways modulo 1e9+7
intution : total sum must be even, then its like counting subsets with sum = total/2 using numbers 1 to n, divide by 2 as both sets are interchangeable
soln : knapsack dp to count subsets with target sum, divide result by 2 using modular inverse

state : dp[s] = no of subsets with sum s
transition : dp[j+i] += dp[j] for each number i from 1 to n (iterate j backwards)
initialization : dp[0] = 1
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

