#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
pair<ll,ll> solve(ll num){
    ll cnt1 = 0,cnt2 = 0;
    while(num%2==0){
        num /= 2;
        cnt1++;
    }
    while(num%5==0){
        num /= 5;
        cnt2++;
    }
    return {cnt1,cnt2}; 
}
ll power(ll b, ll e) {
    ll res = 1;
    while (e) {
        if(e&1)res*=b;
        b*=b;
        e>>=1;
    }
    return res;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        pair<ll,ll> p = solve(n);
        ll cnt1 = p.first, cnt2 = p.second;
        // cout<<"2: "<<cnt1<<" 5:"<<cnt2<<endl;
        ll mini = min(cnt1,cnt2);
        ll ans = n*m;
        // ll val1 = pow(10,mini);
        for(int i=mini;i<=18;i++){
            ll ele1 = max(i-cnt1,0LL);
            ll ele2 = max(i-cnt2,0LL);
            ll val1 = power(2,ele1);
            ll val2 = power(5,ele2);
            ll val = val1 * val2;
            if(val<=m){
                ll ele3 = m/val;
                ans = n*val*ele3; 
                // break;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}