#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
vector<ll> sieve(ll n){
    vector<ll> val(n+1,1);
    val[0] = 0;
    val[1] = 0;
    for(int i=2;i*i<=n;i++){
        if(val[i]==1){
            for(int j=i*i;j<=n;j+=i){
                val[j] = 0;
            }
        }
    }
    return val;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> val = sieve(n);
        vector<ll> pr;
        for(int i=0;i<=n;i++){
            if(val[i]==1){
                pr.push_back(i);
            }
        } 
        int n1 = pr.size();
        
        for(int )  
        
    }
    return 0;
}