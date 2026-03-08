//greedy
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
        vector<ll> v2(n);
        vector<pair<ll,ll>> v3(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=0;i<n;i++){
            cin>>v2[i];
        }
        for(int i=0;i<n;i++){
            v3[i] = {v2[i], v[i]};
        }
        sort(v3.rbegin(), v3.rend());
        unordered_map<ll,vector<ll>> um1;
        for(int i=0;i<n;i++){
            if(um1.find(v3[i].second) == um1.end()){
                um1[v3[i].second].push_back(v3[i].first);
            }else{
                ll ele = um1[v3[i].second].back();
                um1[v3[i].second].push_back(v3[i].first+ele);
            }
        }
        vector<ll> ans(n,0);
        for(auto &it: um1){
            vector<ll> &v1 = it.second;
            ll sz = v1.size();
            // vector<int> vis(sz,0);
            for (int k = 1; k <= sz; k++) {
                ll val1 = sz/k;
                if(val1==0)break;
                ans[k-1]+=v1[val1*k-1];
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}