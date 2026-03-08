#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> minLastIdx(n,n);
        ll ans = 0;
        for(int i=0;i<m;i++){
            ll val1,val2;
            cin>>val1>>val2;
            if(val1 > val2) swap(val1, val2);
            minLastIdx[val1-1] = min(minLastIdx[val1-1], val2-1);
        }
        for(int i=n-2;i>=0;i--){
            minLastIdx[i] = min(minLastIdx[i], minLastIdx[i+1]);
        }
        for(int i=0;i<n;i++){
            ans += minLastIdx[i] - i;
        }
        cout<< ans << endl; 
    }
    return 0;
}