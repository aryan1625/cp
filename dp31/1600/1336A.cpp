#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll dfs(ll node,ll dis,vector<vector<ll>> &adj,vector<ll> &vis,vector<ll> &v){
    vis[node] = 1;
    ll cnt = 0;
    for(auto it: adj[node]){
        if(!vis[it]){
            cnt+=dfs(it,dis+1,adj,vis,v);
        }
    }
    v.push_back(cnt-dis);
    return cnt+1;
}
int main(){
    
        ll n,k;
        cin>>n>>k;
        vector<vector<ll>> adj(n+1);
        for(int i=0;i<n-1;i++){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        k = n-k;
        vector<ll> v;
        vector<ll> vis(n+1,0);
        dfs(1,0,adj,vis,v);
        sort(v.rbegin(),v.rend());
        // vector<ll> istour(n+1,0);
        ll ans = 0;
        for(int i=0;i<k;i++){
            ans+=v[i];
        }
       cout<<ans<<endl;
   
    return 0;
}