#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll power(ll b, ll e){
    ll ans = 1;
    b%=mod;
    while(e>0){
        if(e&1)ans = (ans*b)%mod;
        b = (b*b)%mod;
        e = e>>1;
    }
    return ans;
}
ll modInverse(ll n){
    return power(n,mod-2);
}
ll nCr(ll n, ll r){
    if(r>n)return 0;
    if(r>n/2)r = n-r;
    ll num = 1;
    for(ll i=0;i<r;i++){
        num = (num*(n-i))%mod;
    }
    ll den = 1;
    for(ll i=1;i<=r;i++){
        den = (den*i)%mod;
    }
    return (num*modInverse(den))%mod;
}
int main(){
    
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll ans = n/3;
        ans = nCr(ans,ans/2);
        for(int i=0;i<n;i = i+3){
            sort(v.begin()+i,v.begin()+i+3);
            ll cnt = 1;
            if(v[i]==v[i+1] && v[i+1]==v[i+2])ans = (ans*3)%mod;
            else if(v[i]==v[i+1]){
                ans = (ans*2)%mod;
            }
        }
        cout<<ans<<endl;
    
    return 0;
}