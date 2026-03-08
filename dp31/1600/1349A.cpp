#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll lc(ll a,ll b){
    return (a*b)/__gcd(a,b);
}
int main(){
    
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        // if(n==2){
        //     cout<<lc(v[0],v[1])<<endl;
        //     return 0;
        // }
        // ll val1  = __gcd(v[n-1],v[n-2]);
        ll ans = lc(v[n-1],v[n-2]);
        ll val2 = __gcd(v[n-1],v[n-2]);
        // ll val3 = lc(v[n-1],v[n-2]);
        for(int i=n-3;i>=0;i--){
            ans = __gcd(lc(v[i],val2),ans);
            val2 = __gcd(val2,v[i]);
        }
        cout<<ans<<endl;
    return 0;
}