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
        vector<ll> arr(n);
        vector<ll> arr2(n);
        ll ans = 1LL;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        for(int i=0;i<n;i++){
            if(arr[i] > arr2[i]){
                ans += arr[i]-arr2[i];
            }
        }
        cout<< ans << endl;
        
    }
    return 0;
}