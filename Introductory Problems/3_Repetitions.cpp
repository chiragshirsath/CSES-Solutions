/*
Question : 
input : string s; s.size()<=1e6
operation : finding longest substring with same character of A/C/G/T 
output : length of longest substring with same characters 
intution : brute force in o(n) with checking s[i] and s[i-1]
soln :  maintaining two variables one with current max consecutive chars and one max of total so far while checking s[i] and s[i-1]
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    string s; cin>>s;
    int n=s.size();
    int ans=1; int fans=1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) ans++;
        else ans=1;
        fans=max(fans,ans);
    }
    cout<<fans<<"\n";
}

// this will work for any no of different chars not just A/C/G/T

