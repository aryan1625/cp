#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll dfs(ll src, vector<vector<ll>>&adj, vector<bool>&vis, vector<ll>& depth,vector<ll> &level,ll val){
    vis[src]=true;
    ll md=val;
    level[val]++;
    for(auto i:adj[src]){
        if(!vis[i]){
            ll dep = dfs(i,adj,vis,depth,level, val+1);
            md = max(md,dep);
        }
    }
    depth[src]=md;
    return md;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> adj(n+3);
        for(int i=0;i<n-1;i++){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n+3,false);
        vector<ll> depth(n+3,0);
        vector<ll> level(n+3,0);
        dfs(1,adj,vis,depth,level,1);
        for(int i=n;i>=0;i--){
            level[i]+=level[i+1];
        }
        ll ans = 1e18;
        vector<ll> res(n+3,0);
        vis.assign(n,false);
        queue<ll> q;
        q.push(1);
        res[depth[1]]++;
        vis[1] = 1;
        ll dep = 1;
        while(!q.empty()){
            ll sz = q.size();
            ans = min(ans, level[dep+1]+res[dep-1]);
            dep++;
            res[dep]+=res[dep-1];
            for(int i=0;i<sz;i++){
               ll node = q.front();
                q.pop();
                for(auto child:adj[node]){
                    if(!vis[child]){
                        vis[child]=true;
                        res[depth[child]]++;
                        q.push(child);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}