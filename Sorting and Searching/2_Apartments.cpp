/*
Question : 
input : n applicants, m appartments n,m<= 2e5 , allowed diff k<=1e9, n desired appartment size,m appartment size <=1e9
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
output : number of applicants who will get an appartment
intution : distritibute from the smallest desired appt greedily
soln : go through wishes and using a pointer give the smallest appt possible 
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,m,k; cin>>n>>m>>k;
    int a[n]; int b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n); sort(b,b+m);
    int ans=0;
    int j=0;
    for(int i=0;i<n;i++){
        while(b[j]<a[i]-k and j<m) j++;
        if(j==m) break;
        if(b[j]>=a[i]-k and b[j]<=a[i]+k) {
            ans++; j++;
        }
    }
    cout<<ans<<"\n";
}

