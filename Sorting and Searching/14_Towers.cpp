/*
Question : 
input : n no of cubes <=2e5, size of cubes <=1e9
operation : we can either place cube on top of a bigger existing cube or start a new tower
output : minimum number of towers
intution : greedy brute force as keeping a small tower on smallest possible tower is better or equal to creating new tower always
soln : we greedyly put cube on top of smallest cube possible or create new tower, implementing this using a multiset
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        auto it=s.upper_bound(x);
        if(it!=s.end()) s.erase(it);
        s.insert(x);
    }
    cout<<s.size()<<"\n";
    
}