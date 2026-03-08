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
        vector<ll> ans(n);
        vector<vector<ll>> adj(n);
        for(int i=0;i<n-1;i++){
            ll u,v,x,y;
            cin>>u>>v>>x>>y;
            if(x>y){
                adj[u-1].push_back(v-1);
            }else{
                adj[v-1].push_back(u-1);
            }
        }
        //topo sort
        vector<ll> indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indeg[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<ll> res;
        while(!q.empty()){
            ll val = q.front();
            q.pop();
            res.push_back(val);
            for(auto i: adj[val]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
        ll cnt = n;
        for(int i=0;i<n;i++){
            ans[res[i]] = cnt--;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}