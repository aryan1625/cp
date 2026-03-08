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
        vector<vector<ll>> adj(n+1);
        vector<ll> cnt(n+1);
        for(int i=0;i<n-1;i++){
            int u;
            int v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cnt[u]++;
            cnt[v]++;
        }
        if(n<=2){
            cout<<0<<endl;
            continue;
        }
        set<ll> st;
        for(int i=0;i<=n;i++){
            if(cnt[i]==1){
                st.insert(i);
            }
        }
        ll tot = st.size();
        ll mini = n+1;
        for(int i=0;i<=n;i++){
            ll ele = 0;
            for(int j = 0;j<adj[i].size();j++){
                if(st.find(adj[i][j])!=st.end())ele++;
            }
            mini = min(mini,tot-ele);
        }
        cout<<mini<<endl;

        
    }
    return 0;
}