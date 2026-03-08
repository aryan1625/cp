#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<ll> pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1]+s[i-1]-'0';
        }
        //calculates number of good subarrays till index i 
        ll cnt = 0;
        unordered_map<ll,ll> um;
        for(int i=0;i<=n;i++){
            um[i-pre[i]]++;
        }
        ll ans = 0;
        for(auto it:um){
            ll val = it.second;
            ans += (val*(val-1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}