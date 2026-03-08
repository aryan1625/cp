#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll solve(ll idx, vector<ll>& b, vector<ll>& c,ll k,vector<vector<ll>> &dp){
    int n = b.size();
    if(idx>=n)return 0;
    if(dp[idx][k]!=-1)return dp[idx][k];
    ll ans = 0;
    //pick
    if(k>=b[idx]){
        ans = max(ans,c[idx]+solve(idx+1,b,c,k-b[idx],dp));
    }
    ans = max(ans, solve(idx+1,b,c,k,dp));
    return dp[idx][k] = ans;
}

int main(){
    //precompute for 1e3
    vector<ll> val(1e3+1,100);
    val[1] = 0;
    val[2] = 1;
    for(int i=2;i<=1e3;i++){
        for(int j=i;j>=1;j--){
            ll ele = i+i/j;
            if(ele>1e3)break;
            val[ele] = min(val[ele],1+val[i]);
        }
    }
    // ll maxi = 0;
    // for(int i=1;i<=1e3;i++){
    //     maxi = max(maxi,val[i]);
    // }
    // cout<<maxi<<endl;
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector<ll> c(n);
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        for(int i=0;i<n;i++){
            b[i] = val[b[i]];
        }
        if(k>=12001){
            ll ans = accumulate(c.begin(),c.end(),0LL);
            cout<<ans<<endl;
            continue;
        }
        //pick not pick dp 
        vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
        cout<<solve(0,b,c,k,dp)<<endl;
        
    }
    return 0;
}