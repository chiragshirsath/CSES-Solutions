/*
Question : n books with a price and number of pages 
input :  n no of books <=1000, maximum total price x <=1e5 , price and pages of books hi,si<=1000
output : maximum no of pages we can buy
intution : adding book one by one for each price p what is the max no of pages we can buy
soln : we add books one by one and calculate after each addition what will be max no of pages bought for each price 0 to x , as it depends on a lower price value we iterate price backwards

state : dp[p] represents maximum pages for price p
transition : dp[p]=max(dp[p],pages[currbook]+dp[p-price[currbook]])
initialization : eveything to 0 as for no books at any price max pages are 0
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static int dp[1000010];

int main(){
    ll n, x; cin>>n>>x;
    int price[n]; int pages[n];
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=x; j>=0; j--){
            if(j-price[i]>=0) dp[j]=max(dp[j],pages[i]+dp[j-price[i]]);
        }
    }
    cout<<dp[x]<<"\n";
}

