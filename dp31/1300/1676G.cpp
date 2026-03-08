#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
pair<ll,ll> solve(ll src,vector<ll> adj[],string &s,ll &cnt){
    ll b = 0;
    ll w = 0;
    if(s[src]=='W')w++;
    else{
        b++;
    }
    for(auto i:adj[src]){
        pair<ll,ll> p = solve(i,adj,s,cnt);
        b+=p.first;
        w+=p.second;
    }
    if(b==w){
        cnt++;
    }
    return {b,w};
}
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<ll> a(n-1);
       string s;
       for(int i=0;i<n-1;i++){
        cin>>a[i];
        a[i]-=1;
       }
       cin>>s;
       vector<ll> adj[n];
       for(int i=0;i<n-1;i++){
        adj[a[i]].push_back(i+1);
       }
       ll cnt = 0;
       solve(0,adj,s,cnt);
       cout<<cnt<<endl;

       
    }
    return 0;
}