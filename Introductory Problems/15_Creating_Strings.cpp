/*
Question : 
input : string s, size of string s <=8
output : all strings generated using its characters in sorted order
intution : recursively store all possible strings
soln: use backtracking recusrion to generate and store all strings then sort and print
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> v;

void solve(int n,vector<int>&c,string &ans){
    if(n==ans.size()) {
        v.push_back(ans);
        return;
    }
    for(int i=0;i<26;i++){
        if(c[i]>0){
            c[i]--; 
            ans+=(char)('a'+i);
            solve(n,c,ans);
            c[i]++; ans.pop_back();
        }
    }
}

int main(){
    string s; cin>>s;
    int n=s.size();
    vector<int> c(26);
    for(int i=0;i<n;i++){
        c[s[i]-'a']++;
    }
    string ans="";
    solve(n,c,ans);
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for (int i = 0; i < v.size(); ++i){
        cout<<v[i]<<"\n";
    }
}

// another soln : using next_permutation(s.begin(), s.end())
