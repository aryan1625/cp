#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    vector<ll> vec = {1,3,6,10,15,21,28,36,45,55};
    while(t--){
        ll n;
        cin>>n;
        ll ans = 1;
        ll n2 = 0;
        while(n>0){
            n2 = n2*10+n%10;
            n/=10;
        }
        while(n2>0){
            ll val = n2%10;
            n2/=10;
            ans *= vec[val];
        }
        cout<<ans<<endl;
        
    }
    return 0;
}