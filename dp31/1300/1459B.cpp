#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    ll n;
    cin>>n;
    if(n<=2){
        cout<<4<<endl;
    }else{
        if(n&1){
            ll ele = (n+2)*(n+2)-1;
            cout<<ele/2<<endl;
        }else{
            ll ele = n/2+1;
            cout<<ele*ele<<endl;
        }
    }
    return 0;
}