#include<bits/stdc++.h>
using namespace std;
long long int solve(int n,int k,vector<vector<long long int>>& dp){
    if(n==1)return 0;
    if(k<=1)return INT_MAX;
    if(n<=k)return 1;
    if(dp[n][k]!=-1)return dp[n][k];
    long long int mini = INT_MAX;
    for(int i=k;i>=2;i--){
        int val = n/i;
        int rem = n%i;
        int a = rem==0?0:1;
        mini = min(mini,1+(i-a)*solve(val,k,dp)+a*solve(rem+val,k,dp));
    }
    return dp[n][k] = mini;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        vector<vector<long long int>> dp(n+1,vector<long long int>(k+1,-1));
        cout<<solve(n,k,dp)<<endl;
    }
    return 0;
}
