#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
bool solve(ll mid,vector<ll>& v){
    ll n = v.size();
    for(int i=0;i<n-1;i++){
        if(abs(v[i+1]-v[i])>mid){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("a1actual.txt", "r", stdin);
    freopen("a1output2.txt", "w", stdout);
    ll t;
    cin>>t;
    ll cnt= 1;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll st = 0;
        ll end = 1e5;
        ll ans = 1e5;
        while(st<=end){
            ll mid = st+(end-st)/2;
            if(solve(mid,v)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
    return 0;
}