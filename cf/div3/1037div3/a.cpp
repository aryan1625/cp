#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll solve(ll n){
    int maxi = 9;
    while(n>0){
        int rem = n%10;
        maxi = min(maxi,rem);
        n /= 10;
    }
    return maxi;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
        
    }
    return 0;
}