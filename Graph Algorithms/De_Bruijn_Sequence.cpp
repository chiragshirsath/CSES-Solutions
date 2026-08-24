#include<bits/stdc++.h>
using namespace std;
vector<string> subsets;
unordered_map<string,vector<string>> adj;
vector<string> path;

string to_bin(int n, int k) { 
    string s = "";
    for(int i = 0; i < k; i++) {
        s += to_string(n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

void generate(int k){
    for(int i=0;i<(1<<k);i++) {
        string s=to_bin(i,k);
        subsets.push_back(s);
    }
}

void dfs(string u){
    while(adj[u].size()!=0){
        string v=adj[u].back();
        adj[u].pop_back();

        dfs(v);
    }
    path.push_back(u);
}

int main(){
    int k; cin>>k;
    if(k==1){
        cout<<"01\n"<<endl; 
        return 0;
    }
    generate(k);
    for(int i=0;i<subsets.size();i++){
        string u=subsets[i].substr(0,k-1);
        string v=subsets[i].substr(1,k-1);
        adj[u].push_back(v);
    }

    dfs(subsets[0].substr(0, k-1));
    reverse(path.begin(),path.end());
    string ans=path[0];
    for(int i=1;i<path.size();i++) ans+=path[i].back();
    cout<<ans<<endl;
}