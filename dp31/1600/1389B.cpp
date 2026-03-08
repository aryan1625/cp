#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll solve(ll idx,ll k, ll z,bool fl,vector<ll> &v,vector<vector<vector<ll>>> &dp){
    if(idx<0 || idx>=v.size() || k<0 || z<0) return 0;
    if(k==0) return v[idx];
    if(dp[k][z][fl]!=-1) return dp[k][z][fl];
    ll op1 = solve(idx+1,k-1,z,0,v,dp)+v[idx];
    ll op2 = 0;
    if(z>0 && !fl){
        op2 = solve(idx-1,k-1,z-1,1,v,dp)+v[idx];
    }
    return dp[k][z][fl] = max(op1,op2);
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k,z;
        cin>>n>>k>>z;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        z = min(z,k/2);
        // ll res = 0;
        vector<vector<vector<ll>>> dp(k+1,vector<vector<ll>>(z+1,vector<ll>(2,-1)));
        ll ans = solve(0,k,z,0,v,dp);
        cout<<ans<<endl;
        
        
    }
    return 0;
}