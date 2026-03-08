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
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<ll> val(n,1);
        for(int i=1;i<n;i++){
            val[i] = val[i-1];
            if(v[i]<v[i-1]){
                val[i]++;
            }
        }
        ll ans = 1;
        ll cnt = 0;
        for(ll i=1;i<n;i++){
            if(val[i]==val[i-1]){
                cnt+=val[i]-1;
            }
            ll ele = ((i+1)*(i+2))/2;
            ll ele2 = ((i+1-val[i])*(i+2-val[i]))/2;
            ans += ele-ele2-cnt;
        }
        cout<<ans<<endl;

    }
    return 0;
}