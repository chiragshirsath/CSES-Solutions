/*
Question : 
input : n children <=2e5, weight limit x <=1e9 and weight of children <=x
each gindola can have atmax 2children with total weight <=weight limit
output : minimum number of required gondolas
intution : start from child with max weight and keep him with child with max possible wt
soln : using set we choose the max wt child and put another child with max wt possible and keep on doing to minimize no of gondolas
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,x; cin>>n>>x;
    multiset<int> s;
    for(int i=0;i<n;i++) {
        int p; cin>>p;
        s.insert(p);
    }
    int ans=0;
    while(s.size()){
        auto it=s.end(); it--;
        auto it1=s.upper_bound(x-(*it));
        if(it1!=s.begin()) {
            it1--; 
            if(it1==it) {
                if(it1!=s.begin()) {
                    it1--; 
                    s.erase(it1);
                }
            }
            else s.erase(it1);
        }
        s.erase(it);
        ans++;
    }
    cout<<ans<<"\n";
}

// i did heaviest with heavies fit , even heaviest with lightest fit would work greedily using two pointers
