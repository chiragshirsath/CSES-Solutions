/*
Question : 
input : array size n <=2e5, q queries <=2e5, elements <=1e9
output : for each query sum of elements in range [a,b]
intution : precompute prefix sums and answer each query in O(1)
soln : prefix sum array, answer = pf[b] - pf[a-1]
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    vector<ll> pf(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i]; pf[i+1]=v[i];
    }
    for(int i=1;i<=n;i++) pf[i]+=pf[i-1];
    for(int i=0;i<q;i++){
        int a,b; cin>>a>>b;
        cout<<pf[b]-pf[a-1]<<endl;
    }
}