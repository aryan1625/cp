#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll maxi = 0;
ll dfs(ll src,ll idx, vector<pair<ll,ll>> adj[], map<pair<ll,ll>,ll> &um,vector<ll> &vis){
    ll cnt = 1;
    vis[src] = 1;
    for(auto i: adj[src]){
        if(vis[i.first]) continue;
        auto idx2 = i.second;
        ll ele = dfs(i.first, idx2, adj, um, vis);
        if(idx2<idx){
            ele++;
        }
        cnt = max(cnt, ele);
    }
    return cnt;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v(n-1);
        map<pair<ll,ll>,ll> um;
        for(int i=0;i<n-1;i++){
            cin>>v[i].first>>v[i].second;
            if(v[i].first>v[i].second){
                swap(v[i].first, v[i].second);
            }
            um[{v[i].first, v[i].second}] = i;
        }
        // ll ans = 1;
        vector<pair<ll,ll>> adj[n+1];
        for(int i=0;i<n-1;i++){
            adj[v[i].first].push_back({v[i].second,i});
            adj[v[i].second].push_back({v[i].first,i});
        }
        vector<ll> vis(n+1, 0);
        ll ans = dfs(1,-1,adj,um,vis);   
        cout<<ans<<endl;
        
        
    }
    return 0;
}