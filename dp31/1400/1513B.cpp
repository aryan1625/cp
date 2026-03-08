//bit manipulation, greedy, observation
#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
using ll = long long ;
using ld = long double ;
//obs 1 at end of arrays the number should be same

//by obs 2 we can also determine that 
//if a,b,c,d,e,a   if b&c&d&e is a then the permutation will satisfy (a1&a2&...ai== ai+1 & ai+2 & ... an) for all i

//from this obs2 we can determine obs3 that is (and) of all elements = a then 
// we need to find permutations such that it is of form-> (a.....a)
ll fact(ll n){
    ll val = 1;
    for(int i=1;i<=n;i++){
        val = (val*i)%mod;
    }
    return val%mod;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll val1 = v[0];
        unordered_map<ll,ll> um;
        um[v[0]]++;
        for(int i=1;i<n;i++){
            val1 &= v[i];
            um[v[i]]++;
        }
        if(um[val1]<=1){
            cout<<0<<endl;
            continue;
        }
        ll ele = fact(n-2)%mod;
        ll ele2 = (um[val1]*(um[val1]-1))%mod;
        ll ans = (ele*ele2)%mod;
        cout<<ans<<endl;
    }
    return 0;
}