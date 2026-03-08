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
        ll n,x,m;
        cin>>n>>x>>m;
        vector<pair<ll,ll>> v(m);
        for(int i=0;i<m;i++){
            cin>>v[i].first>>v[i].second;
        }
        ll ans = 1;
        ll prev = x;
        ll nxt = x;
        for(int i=0;i<m;i++){
            if((prev>=v[i].first && prev<=v[i].second)||(nxt>=v[i].first && nxt<=v[i].second)){
                prev = min(prev,v[i].first);
                nxt = max(nxt,v[i].second);
            }
        }
        ans = max(ans,nxt-prev+1);
        cout<<ans<<endl;
    }
    return 0;
}