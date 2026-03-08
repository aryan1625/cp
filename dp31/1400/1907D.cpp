#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
bool solve(ll mid,vector<pair<ll,ll>> &vec){
    int n = vec.size();
    ll a = 0;
    ll b = 0;
    for(int i=0;i<n;i++){
        ll l1 = vec[i].first;
        ll r1 = vec[i].second;
        ll val1= max(0LL,a-mid);
        ll val2= b+mid;
        if(val2<l1 || r1<val1)return false;
        a = max(l1,val1);
        b = min(r1,val2);
    }
    return true;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first>>v[i].second;
        }
        ll ans = 1e9;
        //bs
        ll st = 0;
        ll end = 1e10;
        while(st<=end){
            ll mid = st+(end-st)/2;
            if(solve(mid,v)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        cout<<ans<<endl;

        
    }
    return 0;
}