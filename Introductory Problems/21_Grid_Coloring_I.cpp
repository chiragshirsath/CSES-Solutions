/*
Question : 
input : int n,m<=500
operation : change the character in current cell and it should not match any adjacent cell
output : final grid
intution : either brute force or parity of adjacent cells is diff than current cell may help
soln: both works either brute force greedily from start or for cells with diff parity assign 2 letters to place
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x; cin>>x;
            if((i+j) & 1){
                if(x=='A') cout<<'B';
                else cout<<"A";
            }
            else{
                if(x=='C') cout<<'D';
                else cout<<"C";
            }
        }
        cout<<"\n";
    }
}
