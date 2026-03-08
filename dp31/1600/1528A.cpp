#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
vector<ll> dp1(200005,0);
vector<ll> dp2(200005,0);
void dfs(ll node,ll par,vector<vector<ll>> &adj,vector<pair<ll,ll>> &v,vector<ll> &dp1,vector<ll> &dp2){
    for(auto child:adj[node]){
        if(child==par) continue;
        dfs(child,node,adj,v,dp1,dp2);
        dp1[node]+=max(abs(v[node].first - v[child].first)+dp1[child],abs(v[node].first - v[child].second)+dp2[child]);
        dp2[node]+=max(abs(v[node].second - v[child].first)+dp1[child],abs(v[node].second - v[child].second)+dp2[child]);
    }
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++){
            ll l,r;
            cin>>l>>r;
            v[i] = {l,r};
        }
        vector<vector<ll>> adj(n);
        for(int i=0;i<n-1;i++){
            ll u,v1;
            cin>>u>>v1;
            u--;v1--;
            adj[u].push_back(v1);
            adj[v1].push_back(u);
        }
        ll maxi = 0;
        ll maxId = 0;
        for(int i=0;i<n;i++){
            if(adj[i].size()>maxi){
                maxi = adj[i].size();
                maxId = i;
            }
        }
        dp1.assign(n,0);
        dp2.assign(n,0);
        dfs(maxId,-1,adj,v,dp1,dp2);
        cout<<max(dp1[maxId],dp2[maxId])<<endl;


    }
    return 0;
}