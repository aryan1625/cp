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
        vector<ll> v(n);
        unordered_map<ll,ll> um;
        for(int i=0;i<n;i++){
            cin>>v[i];
            um[v[i]]++;
        }
        //this is the most important part sorting the map in descending order
        map<ll,ll,greater<ll>> um2;
        for(auto i:um){
            um2[i.second]++;
        }
        ll ans = 0;
        ll cnt = INT_MAX;
        for(auto i: um2){
            ll ele = min(i.first,cnt);
            ans += (ele*(ele+1))/2;
            ll val = ele-i.second;
            if(i.second<ele){
                ans-=(val*(val+1))/2;
                cnt = val;
            }else{
                break;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}