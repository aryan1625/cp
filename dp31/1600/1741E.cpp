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
        vector<ll> dp(n+1,0);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=1;i<=n;i++){
            //left
            if(i-v[i-1]-1>=0 && dp[i-v[i-1]-1]){
                dp[i] = 1;
            }
            if(i+v[i-1]<=n && dp[i-1]==1){
                dp[i+v[i-1]] = 1;
            }
        }
        if(dp[n]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        

        
    }
    return 0;
}