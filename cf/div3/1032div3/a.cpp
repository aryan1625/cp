#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,s;
        cin>>n>>s;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll ans = 0;
        ans = v[n-1]-v[0] + min(abs(s-v[0]),abs(v[n-1]-s));
        cout<<ans<<endl;

        
    }
    return 0;
}