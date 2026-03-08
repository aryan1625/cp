#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
void solve(ll n){
    ll a = -1,b = -1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            a = n/i;
            b = n-a;
            break;
        }
    }
    if(a==-1 && b==-1){
        a = 1;
        b = n-1;
    }
    cout<<a<<" "<<b<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        solve(n);
    }
    return 0;
}