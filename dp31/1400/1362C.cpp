#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
// void solve(ll n){
//     // ll ans = 0;
//     for(int i=0;i<n;i++){
//         ll val1 = i;
//         ll val2 = i+1;
//         ll ans = 0;
//         for(int j=0;j<32;j++){
//             if((val1&(1LL<<j))!=(val2&(1LL<<j))){
//                 ans++;
//             }
//         }
//         cout<<ans<<" ";
//     }
//     cout<<endl;
// }
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll val1 = log2l(n);
        vector<ll> v;
        for(int i=0;i<=val1+1;i++){
            v.push_back(1LL<<i);
        }
        ll ans = 0;
        for(ll i=1;i<=val1+1;i++){
            ll val1 = n-v[i-1];
            ans = ans + i*(val1/v[i] + 1);
        }
        cout<<ans<<endl;
    }
    // ll a;
    // cin>>a;
    // solve(a);
    return 0;
}