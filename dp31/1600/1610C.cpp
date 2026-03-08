#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
bool solve(ll val,vector<pair<ll,ll>> &v){
    ll n = v.size();
    ll cnt = 0;
    for(int i=0;i<n;i++){
        if(v[i].first>=val-1-cnt && v[i].second>=cnt){
            cnt++;
        }
        if(cnt>=val){
            return true;
        }
    }
    return cnt>=val;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++){
            ll val1,val2;
            cin>>val1>>val2;
            v[i] = {val1,val2};
        }
        ll st = 0;
        ll end = n;
        ll ans = 0;
        while(st<=end){
            ll mid = st+(end-st)/2;
            if(solve(mid,v)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}