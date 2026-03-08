#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
vector<int> coins;
int change(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    // return solve(amount,n-1,coins,dp);
    for(int i=0;i<=amount;i++){
        dp[0][i]=i%coins[0]==0?1:0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=amount;j++){
            int take=0;
            if(j>=coins[i]){
                take=dp[i][j-coins[i]]%mod;
            }
            int nottake=dp[i-1][j]%mod;
            dp[i][j]=(take+nottake)%mod;
        }
    }
    return dp[n-1][amount];
}
int main(){
    int val = 4;
    int cnt = 2;
    while(val<=4000000){
        coins.push_back(val);
        val = pow(2,cnt+1)*cnt;
        cnt++;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<change(n,coins)<<endl;
    }
    return 0;
}