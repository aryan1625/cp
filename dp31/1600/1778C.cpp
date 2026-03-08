// bitmask wow!
#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string a,b;
        cin>>a;
        cin>>b;
        ll cnt = 1;
        unordered_map<char,ll> um;
        for(int i=0;i<n;i++){
            if(um.find(a[i])==um.end()){
                um[a[i]] = cnt;
                cnt++;
            }
        }
        ll sz = um.size();
        ll val = (1<<sz)-1;
        ll ans = 0;
        for(int i=0;i<=val;i++){
            ll n1 = __builtin_popcount(i);
            if(n1>k)continue;
            ll total = 0;
            ll cur = 0;
            for(int j=0;j<n;j++){
                if(a[j]==b[j]){
                    cur++;
                    continue;
                }
                ll ele = um[a[j]]-1;
                if((i>>ele)&1){
                    cur++;
                }else{
                    total = total + (cur*(cur+1))/2;
                    cur = 0;
                }
            }
            total = total + (cur*(cur+1))/2;
            ans = max(ans,total);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}