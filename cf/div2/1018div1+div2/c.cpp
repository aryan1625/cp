#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(vector<vector<ll>> &h,vector<ll>&a){
    int n = h.size();
    ll maxi = 1e18;
    vector<vector<ll>> dp(n,vector<ll>(2,maxi));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for(int i=1;i<n;i++){
        //implement the check case if we can do that particular operation or not 
        // we have to check for every columnnnnnnn fuckkkkk!!!!!!
        bool a1=false,a2=false,a3=false;
        for(int j=0;j<n;j++){
            //if we didnt increase the last one we have to increase this one 
            //TF or FT
            if(h[i][j]==h[i-1][j]){
               a1 = true;
            }
            //if we increased the last one we have to increase this one
            //TT or FF or FT
            else if(h[i][j]==h[i-1][j]+1){
                a2 = true;
            }
            //TT or FF or TF
            else if(h[i][j]+1==h[i-1][j]){
                a3 = true;
            }
        }
        //now check if we can do the operation or not
        if(a1 && a2 && a3){
            return maxi;
        }//only ft
        else if(a1 && a2){
            dp[i][0] = maxi;
            dp[i][1] = dp[i-1][0]+a[i];
        }//only tf
        else if(a1 && a3){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = maxi;
        }//tt or ff
        else if(a2 && a3){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1]+a[i];
        }//tf or ft
        else if(a1){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0]+a[i];  
        }//tt or ff or ft
        else if(a2){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = min(dp[i-1][1],dp[i-1][0])+a[i]; 
        }//tt or ff or tf
        else if(a3){
            dp[i][0] = min(dp[i-1][1],dp[i-1][0]);
            dp[i][1] = dp[i-1][1]+a[i]; 
        }//everything allowed
        else{
            dp[i][0] = min(dp[i-1][1],dp[i-1][0]);
            dp[i][1] = dp[i][0]+a[i];
        }
    }
    ll ans = min(dp[n-1][0],dp[n-1][1]);
    if(ans>=maxi){
        return maxi;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<ll>> h(n,vector<ll>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>h[i][j];
            }
        }
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll> b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        //row operations 
        ll r = solve(h,a);        
        //transpose
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(h[i][j],h[j][i]);
            }
        }
        //column operations 
        ll c = solve(h,b);
        ll ans = r+c;
        if(ans>=1e18){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}