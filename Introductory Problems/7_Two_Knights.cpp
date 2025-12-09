/*
Question : 
input : int n; n<=1e4
output : number of ways 2 knights can be placed on a kxk chess board for k=1,2,3,...n
intution : place the first knight then think for the second, ans will be same for specific regions on the board ex: places where no of places first knight attacks is same
soln : we calculate ans for these limited cases of placing both knights which will be total - placing a knight and places where it attacks,  and add it up
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n; cin>>n;
    for(int i=1;i<=n;i++){
        //handling edge cases
        if(i==1) cout<<0<<"\n";
        else if(i==2) cout<<6<<"\n";
        else if(i==3) cout<<28<<"\n";
        else{
            ll ans=0; 
            //knight has 2 places to attack (corner cells[4]) 
            ans+=1ll*4*(i*i-3);
            //knight has 3 places to attack (cells adjacent to corner cells[8])
            ans+=1ll*8*(i*i-4);
            //knight has 4 places to attack (cells diagonal to corner cells[4]+cells remaining in first/last row/col [4*(i-4)])
            ans+=1ll*(4+4*(i-4))*(i*i-5);
            //knight has 6 places to attack (cells remaining in second/lastsecond row/col [4*(i-4)])
            ans+=1ll*(4*(i-4))*(i*i-7);
            //knight has 8 places to attack (the (i-4)*(i-4) grid)
            ans+=1ll*((i-4)*(i-4))*(i*i-9);
            // each case gets counted twice so we divide by two
            cout<<ans/2<<"\n";
        }
    }
}

