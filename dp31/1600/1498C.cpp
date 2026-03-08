#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
using ll = long long ;
using ld = long double ;
//https://www.youtube.com/watch?v=BKLEkA1dSoo
ll dp[1005][1005];
ll solve(ll i, ll k, ll n){
    if(i==0 || k<=1)return 1;
    if(dp[i][k]!=0) return dp[i][k];
    return dp[i][k] = (solve(i-1,k,n)+solve(n-i,k-1,n))%mod;
}
int main(){
   
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        memset(dp,0,sizeof(dp));
        cout<<solve(n,k,n)<<endl;
        
    }
    return 0;
}