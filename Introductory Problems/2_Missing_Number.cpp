/*
Question : 
input : int n; 2<=n<=2e5 and n-1 numbers
operation : to find the missing number
output : missing number
intution : constraint is of o(n) or o(nlogn) so we can sort
soln : sort(nlogn) and search o(n) 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    int arr[n-1];
    for(int i=0; i<n-1; i++) cin>>arr[i];
    sort(arr,arr+n-1);
    bool ok=true;
    for(int i=0; i<n-1; i++){
        if(arr[i]!=i+1){
            ok=false;
            cout<<i+1<<"\n"; break;
        }
    }
    if(ok) cout<<n<<"\n";
}

/*
better solutions:
1) using a map/bool array as constraints are till 2e5 
o(n) time and o(n) space
2) calculating sum then subtract from n*(n+1)/2 [1+2+...+n]
o(n) time and o(1) space
*/ 
