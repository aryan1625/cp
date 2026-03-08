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
        multiset<ll> ms;
        ms.insert(1);
        vector<ll> b(n);
        for(int i=0;i<n-1;i++){
            ll val ;
            cin>>val;
            ms.insert(val);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        ll ans = 0;
        for(auto i:b){
            auto it = ms.lower_bound(i);
            if(it==ms.begin()){
                ans++;
                continue;
            }else{
                it--;
                ms.erase(it);
            }
        }
        cout<<ans<<endl;

        
    }
    return 0;
}