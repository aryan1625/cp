#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
//bs + prefix sum wow!!
bool solve(vector<pair<ll,ll>> &v, ll mid, vector<ll> &queries, ll n){
    vector<ll>pre(n+1,0);
    for(int i=0;i<mid;i++){
        pre[queries[i]+1]++;
    }
    for(int i=1;i<=n;i++){
        pre[i]+=pre[i-1];
    }
    ll m = v.size();
    for(int i=0;i<m;i++){
        ll val1 = v[i].first;
        ll val2 = v[i].second;
        ll cnt = pre[val2+1]-pre[val1];
        if(cnt>=((val2-val1+1)/2+1)){
            return true;
        }
        
    }
    return false;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,ll>> v(m);
        vector<ll> diff(m,0);
        for(int i=0;i<m;i++){
            ll val1,val2;
            cin>>val1>>val2;
            v[i] = {val1-1,val2-1};
            // diff[i] = (val2-val1+1)/2+1;
        }
        ll q;
        cin>>q;
        vector<ll> queries(q);
        for(int i=0;i<q;i++){
            ll val;
            cin>>val;
            queries[i] = val-1; 
        }
        ll st = 1;
        ll end= q;
        ll ans = -1;
        while(st<=end){
            ll mid = st+(end-st)/2;
            if(solve(v,mid,queries,n)){
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