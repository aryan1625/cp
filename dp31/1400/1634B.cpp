//odd even bcccc!!!
#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        bool prev = (v[0]&1)?1:0;
        for(int i=1;i<n;i++){
            if(v[i]&1){
                prev = !prev;
            }
        }
        ll val1 = prev^x;
        // ll val2 = prev^(x+1);/
        ll bit = (y&1)?1:0;
        ll bit2 = (val1&1)?1:0;
        if(bit==bit2){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
        
    }
    return 0;
}