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
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        //use dp to find the maximum number of elements at index i 
        vector<ll> dp(n+1, 1);
        ll ans = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    ll val1 =j;
                    ll val2 = i/j;
                    if(v[val1-1]<v[i-1]){
                        dp[i] = max(dp[i], dp[j]+1);
                    }
                    if(v[val2-1]<v[i-1]){
                        dp[i] = max(dp[i], dp[val2]+1);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}