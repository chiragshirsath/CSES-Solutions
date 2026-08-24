/*
Question : find all possible sums using given coins (each coin used atmost once)
input : n coins <=100 with values <=1000
output : all possible sums in increasing order
intution : similar to subset sum, for each coin mark new sums that become possible
soln : use boolean dp, for each coin iterate backwards and mark sum+coin[i] as possible if sum was possible

state : poss[s] = true if sum s is achievable
transition : poss[j+arr[i]] = true if poss[j] is true
initialization : poss[0] = true
*/


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
   int n; cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
   vector<bool> poss(100010);
   poss[0]=1;
   for(int i=0;i<n;i++){
    for(int j=100000;j>=0;j--){
        if(poss[j]) poss[j+arr[i]]=1;
    }
   }
   vector<int> ans;
   for(int i=1;i<=100000;i++){
    if(poss[i]) ans.push_back(i);
   }
   cout<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
   cout<<"\n";
}