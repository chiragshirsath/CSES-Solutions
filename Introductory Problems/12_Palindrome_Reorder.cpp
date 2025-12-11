/*
Question : 
input : string s; length of string n<=1e6
output : reordered string in the form of palindrome , NO SOLUTION if not possible
intution : if possible then we can sort and create palindrome using freq of each letter
soln : check if possible to transform in palindrome if odd freq is <=1 and then make palindrome by adding half freq from a-z, odd freq char,then z-a 
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    string s; cin>>s;
    int n=s.size();
    vector<int> freq(26);
    for(int i=0;i<n;i++) freq[s[i]-'A']++;
    int ct=0;
    for(int i=0;i<26;i++) if(freq[i]&1) ct++;
    if(ct>1) cout<<"NO SOLUTION\n";
    else{
        for(int i=0;i<26;i++){
            for (int j = 0; j < freq[i]/2; ++j){
                cout<<(char)('A'+i);
            }
        }
        for(int i=0;i<26;i++) if(freq[i]&1) cout<<(char)('A'+i);
        for(int i=25;i>=0;i--){
            for (int j = 0; j < freq[i]/2; ++j){
                cout<<(char)('A'+i);
            }
        }
        cout<<"\n";
    }
}