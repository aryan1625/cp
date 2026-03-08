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
        vector<ll> mini(n);
        vector<ll> maxi(n);
        mini[0] = v[0];
        maxi[n-1] = v[n-1];
        for(int i=1;i<n;i++){
            mini[i] = min(mini[i-1], v[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxi[i] = max(maxi[i+1], v[i]);
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(mini[i]==v[i] || maxi[i]==v[i]){
                ans += '1';
            }else{
                ans += '0';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}