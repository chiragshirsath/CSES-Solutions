/*
Question : given integer n we can subtract one of digits from number
input : integer n <=1e6
output : minimum steps to make n 0
intution : picking the biggest digit for a no 
soln : the ans will be 1+ans of no-biggestdigit

state : dp[number] representing minimum no of steps to make number 0
transition : dp[number]=dp[number-(greatest digit of no)]+1
initialization : for i: 1 to 9 dp[i]=1
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static int dp[2000000];

int main(){
    ll n; cin>>n;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        if(i<10) dp[i]=1;
        else{
            int d=0;
            int k=i;
            while(k>0){
                d=max(d,k%10);
                k/=10;
            }
            dp[i]=dp[i-d]+1;
        }
    }
    cout<<dp[n]<<"\n";
}
