//prefix suffix!!!!!
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
        ll ans = LLONG_MAX;
        vector<ll> v;
        vector<ll> pre(n,0);
        vector<ll> suf(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='*')v.push_back(i);
        }
        ll sz = v.size();
        if(sz==0){
            cout<<0<<endl;
            continue;
        }
        vector<ll> vpre(sz);
        vector<ll> vsuf(sz);
        vpre[0] = v[0];
        vsuf[sz-1] = v[sz-1];
        for(int i=1;i<sz;i++){
            vpre[i] = vpre[i-1]+v[i];
        }
        for(int i=sz-2;i>=0;i--){
            vsuf[i] = vsuf[i+1]+v[i];
        }
        for(int i=0;i<n;i++){
            auto it = lower_bound(v.begin(), v.end(), i);
            if(it==v.begin())continue;
            if(it==v.end())it--;
            else if(*it!=i)it--;
            ll idx = it-v.begin();
            ll val1 = (idx+1)*i-vpre[idx]-((idx*(idx+1))/2);
            pre[i] = val1;  
        }
        for(int i=n-1;i>=0;i--){
            auto it = lower_bound(v.begin(), v.end(), i);
            if(it==v.end())continue;
            ll idx = it-v.begin();
            ll cnt = v.end()-it-1;
            ll val1 = vsuf[idx]-(cnt+1)*i-((cnt*(cnt+1))/2);
            suf[i] = val1; 
        }
        for(int i=0;i<n;i++){
            ans = min(ans, pre[i]+suf[i]);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}