#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    
    ll n;
    cin>>n;
    vector<ll> v(n);
    vector<ll>pre(n+1,0);
    map<ll,ll> m;
    m[0] = 1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        pre[i+1] = pre[i];
        if(v[i]<0)pre[i+1]++;
        m[pre[i+1]]++;
    }
    ll val = pre[n];
    vector<ll> dp(val+1,0);
    // dp[0] = m[0];
    for(int i=1;i<=val;i++){
        dp[i] = m[i]*m[i-1];
        if(i>=2){
            dp[i]+=(m[i]*dp[i-2])/m[i-2];
        }
    }
    ll ans = 0;
    for(int i=0;i<=val;i++){
        ans+=dp[i];
    }
    ll tot = (n*(n+1))/2;
    cout<<ans<<" "<<tot-ans<<endl;
    return 0;
}