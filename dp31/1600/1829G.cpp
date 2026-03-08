#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    vector<ll> dp(1e6+5,0);
    for(ll i=0;i<=1e6+1;i++){
        dp[i] = i*i;
    }
    dp[2] += dp[1];
    dp[3] += dp[1];

    //fix boundaries of the pyramid
    ll cnt = 2;
    ll i = 2;

    while(i+cnt<=1e6+1){
        dp[i+cnt] += dp[i];
        i = i+cnt;
        cnt++;
    }
    i = 3;
    cnt = 3;
    while(i+cnt<=1e6+1){
        dp[i+cnt] += dp[i];
        i = i+cnt;
        cnt++;
    }
    cnt = 4;
    bool flag = true;
    for(ll i=3;i<=2023;i++){
        for(ll j = cnt+1; j<cnt+i-1;j++){
            if(j>=1e6+1){
                flag = false;
                break;
            }
            dp[j] += dp[j-i]+dp[j-i+1] - dp[j-2*i+2];
        }
        if(!flag)break;
        cnt += i;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
       cout<<dp[n]<<endl;   
        
    }
    return 0;
}