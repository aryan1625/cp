//policy based data structure bkc!!
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;   
        cin>>n;
        vector<pair<ll,ll>> v(n);
        ordered_set<ll> s1;
        for(int i=0;i<n;i++){
            cin>>v[i].first >> v[i].second; 
            s1.insert(v[i].second);
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll val1 = v[i].second;
            ans += s1.order_of_key(val1);
            s1.erase(val1);
        }
        cout<<ans<<endl;
    }
    return 0;
}