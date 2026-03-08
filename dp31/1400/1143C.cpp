#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
void dfs(ll src,vector<vector<ll>> &adj,vector<ll>& marked,vector<ll> &ans){
    bool val = marked[src]==1?true:false;
    for(auto i:adj[src]){
        val = val & marked[i];
        dfs(i,adj,marked,ans);
    }
    if(val){
        // cout<<"babe!!"<<endl;
        ans.push_back(src);
    }
    return;
}
int main(){
    ll n;
    cin>>n;
    // vector<ll> v(n);
    ll rt = -1;
    vector<vector<ll>> adj(n+1);
    vector<ll> marked(n+1,0);
    for(int i=0;i<n;i++){
        ll val1,val2;
        cin>>val1>>val2;
        marked[i+1] = val2;
        if(val1==-1){
            rt = i+1;
            continue;
        }
        adj[val1].push_back(i+1);
    }
    vector<ll> ans;
    dfs(rt,adj,marked,ans);
    if(ans.empty()){
        cout<<-1<<endl;
    }else{
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
     
    return 0;
}