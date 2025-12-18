/*
Question : 
input : string s with length <=1e6
output : lexicographically minimal string formed by reordering the characters so that no two adjacent characters are the same
intution : greedy/bruteforce choosing the min char at curr position which also doesnt make it impossible to form
soln: for a possible ans the max freq should be less than remaining elements+1, then we choose the min char not equal to prev char untill again the possible condition is satisfied after that we put max freq char alternate and other best chars in free spaces
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getmax(vector<ll> &freq){
    ll mx=0;
    for(int j=0;j<26;j++) mx=max(mx,freq[j]);
    return mx;
}
char getmaxchar(vector<ll> &freq){
    ll mx=getmax(freq);
    for(int j=0;j<26;j++) 
    if(freq[j]==mx) return (char)(j+'A');
    return '0';
}
void addchar(string &ans,vector<ll> &freq){
    for(int j=0;j<26;j++){
        if(freq[j]>0 and ((int)ans.size()==0 or (ans.back()-'A')!=j)){
            ans+='A'+j;
            freq[j]--; 
            break;
        }
    }
}

int main(){
    string s; cin>>s; ll n=s.size();
    vector<ll> freq(26);
    for(int i=0;i<n;i++) freq[s[i]-'A']++;
    string ans;
    if(2*getmax(freq)<=n+1){
        ll k=n; ll p=0;
        for(int i=0;i<n;i++){
            ll mx=getmax(freq);
            if(k>=2*mx){
                addchar(ans,freq); k--;
            }
            else{
                if(p&1) addchar(ans,freq);
                else ans+=getmaxchar(freq);
                p++;
            }
        }
    }
    else ans="-1";
    cout<<ans<<"\n";
}