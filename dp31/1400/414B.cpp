//very very imp
//dp + math
//find the factors of each number and then use them to find the number of ways
#include<bits/stdc++.h>
using namespace std;
int mod  = 1e9+7;
using ll = long long ;
using ld = long double ;
void findFct(ll n, vector<vector<ll>> &factr){
    factr[n].push_back(1);
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            factr[n].push_back(i);
            if((n/i)!=i){
                factr[n].push_back(n/i);
            }
        }
    }
    return;
}
int main(){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,1));
    vector<vector<ll>> factr(n+1);
    for(int i=2;i<=n;i++){
        findFct(i,factr);
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            dp[i][j] = dp[i][j-1];
            for(auto &it: factr[i]){
                dp[i][j] = (dp[i][j]+dp[it][j-1])%mod;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans = (ans + dp[i][k])%mod;
    }
    cout<<ans<<endl;
    return 0;
}