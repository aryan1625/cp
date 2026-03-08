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
        if(n==2){
            if(v[1]>v[0]){
                cout<<0<<endl;
            }else{
                cout<<v[0]-v[1]<<endl;
            }
            continue;
        }
        ll ans = 0;
        for(int i=0;i<n-1;i=i+2){
            ll val = v[i];
            if(i+2<n){
                val += v[i+2];
            }
            if(val<=v[i+1])continue;
            ans += val-v[i+1];
            if(i+2<n){
                v[i+2] = max(v[i+1]-v[i],0LL);
                // else{
                //     v[i+2] = 0;
                // }
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}