/*
Question : 
input : no of sticks n <= 2e5,length of sticks <=1e9
operation : Your task is to modify the sticks so that each stick has the same length by lengthen and shorten each stick at a cost of difference of length  
output : minimum total cost
intution : checkin in ranges what affects the cost, the no of sticks greater than length cost dec while for others cost inc so best to go for middle element in sorted lengths
soln : the minimum cost will be for making all sticks to lenght of the middle sticks in sorted order
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    ll a[n]; 
    for(int i=0;i<n;i++) cin>>a[i]; 
    sort(a,a+n);
    ll x=a[n/2],y=a[(n-1)/2];
    ll a1=0,a2=0;
    for(int i=0;i<n;i++) {
        a1+=abs(x-a[i]); a2+=abs(y-a[i]);
    }
    cout<<min(a1,a2)<<"\n";
}

