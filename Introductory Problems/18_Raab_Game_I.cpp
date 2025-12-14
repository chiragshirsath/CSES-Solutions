/*
Question : 
input : t testcases <=1000,no of cards<=100,score of player1,2 <=n
game: 2 players each having cards 1 to n, places 1 card per turn, player with bigger card gets a point
output : given final score was a game possible, if yes a valid game
intution : a+b<=n and a==0,b==0 for 0 score is the condition for a valid game, we can fix order for a player then adjust for the other
soln: to print lets assume p1 has a score which is small then for a we print n to 1 for p1 and for p2 he will first play cards n-b to n-b-a (this will earn a points to p1) then n to n-b (this will earn b points to p2) then remaining cards n-b-a to 1 (draws)
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll a,b; cin>>a>>b;
        if(a+b>n or (a!=b and (a==0 or b==0))){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        if(a<b){
            for(int i=n;i>=1;i--) cout<<i<<" ";     
            cout<<"\n";
            for(int i=n-b;i>n-b-a;i--) cout<<i<<" ";
            for(int i=n;i>n-b;i--) cout<<i<<" ";
            for(int i=n-b-a;i>=1;i--) cout<<i<<" ";
            cout<<"\n";
        }
        else if(a>b){
            for(int i=n-a;i>n-a-b;i--) cout<<i<<" ";
            for(int i=n;i>n-a;i--) cout<<i<<" ";
            for(int i=n-a-b;i>=1;i--) cout<<i<<" ";
            cout<<"\n";
            for(int i=n;i>=1;i--) cout<<i<<" ";
            cout<<"\n";
        }
        else{
            for(int i=1;i<=n;i++) cout<<i<<" ";     
            cout<<"\n";
            for(int i=1;i<=2*a;i+=2) cout<<i+1<<" "<<i<<" ";
            for(int i=2*a+1;i<=n;i++) cout<<i<<" ";
            cout<<"\n";
        }
    }
}
