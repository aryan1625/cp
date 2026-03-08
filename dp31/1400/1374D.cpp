#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll power(ll a,ll b){
    ll ans = 1LL;
    while(b){
        if(b&1)ans= ans*a;
        a = a*a;
        b/=2;
    }
    return ans;
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
        sort(v.begin(), v.end());
        ll ans = 0;
        unordered_map<ll,ll> um;
        bool flag = false;
        for(int i=0;i<n;i++){
            ll val = k-v[i]%k;
            // cout<<val<<" ";
            if(val==k)continue;
            flag = true;
            if(um.find(val) == um.end()){
                um[val] = 1;
            }else{
                um[val]++;
            }
            ans = max(ans,val+k*(um[val]-1));
        }
        if(!flag)cout<<0<<endl;
        else{
            cout<<ans+1<<endl;
        }
    }
    return 0;
}