/*
Question : 
input : int n <= 2e5 , k<=1e9
game : n children in circle, every (k+1)th child is removed
output : the removal order
intution : brute force using set maintaining children 1 to n we can use modulo when k is large also we need ordered set to find k+1th element
soln : we can use a orderedset keeping 1 to n and current index according to which we can remove child finding it by find_by_order , taking modulo of current index by size of set and print no of child removed
*/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
const ll mod = 1000000007;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k; cin>>n>>k; 
    ordered_set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    int q=0; 
    while(s.size()>0){
        q+=k; q%=s.size();
       auto it=s.find_by_order(q);
       int p=*it;
       cout<<p<<" "; s.erase(p);
    }
} 