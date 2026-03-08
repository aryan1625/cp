#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll solve(ll idx, bool flag,vector<ll> &v, vector<ll> &v2,vector<vector<ll>> &dp){
    int n = v.size();
    if(idx>=n)return 0;
    ll maxi = 0;
    if(dp[idx][flag]!=-1)return dp[idx][flag];
    if(flag){
        //take or not take
        maxi = max(maxi,solve(idx+1,flag,v,v2,dp));
        maxi = max(maxi,v[idx]+solve(idx+1,!flag,v,v2,dp));
    }else{
        //take or not take
        maxi = max(maxi,solve(idx+1,flag,v,v2,dp));
        maxi = max(maxi,v2[idx]+solve(idx+1,!flag,v,v2,dp));
    }
    return dp[idx][flag] = maxi;
}
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> v2(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
    cout<<max(solve(0,0,v,v2,dp),solve(0,1,v,v2,dp))<<endl;
    return 0;
}