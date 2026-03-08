#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        if(b>=a){
            ll val = b+n;
            if(val&1){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }
        }
        else{
            ll val1 = a+n;
            ll val2 = b+n;
            if((val1&1) || (val2&1)){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }
        }
        
    }
    return 0;
}