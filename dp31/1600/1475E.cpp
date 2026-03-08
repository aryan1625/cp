#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
using ll = long long ;
using ld = long double ;
ll ncr(ll n,ll r){
    if(r>n) return 0;
    ll numerator = 1;
    ll denominator = 1;
    for(int i=0;i<r;i++){
        numerator = (numerator*(n-i))%mod;
        denominator = (denominator*(i+1))%mod;
    }
    ll inv = 1, b = denominator, p = mod-2;
    while(p){
        if(p&1) inv = (inv*b)%mod;
        b = (b*b)%mod;
        p>>=1;
    }
    return (numerator*inv)%mod;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.rbegin(),v.rend());
        ll ans = 0;
        ll val = v[k-1];
        ll cnt = 0;
        ll cnt2 = 0;
        for(int i=0;i<n;i++){
            if(v[i]==val)cnt++;
        }
        for(int i=0;i<k;i++){
            if(v[i]==val)cnt2++;
        }
        cout<<ncr(cnt,cnt2)<<endl;
    }
    return 0;
}