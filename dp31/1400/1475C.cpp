#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,k;
        cin>>a>>b>>k;
        vector<ll> arr(k);
        vector<ll> arr2(k);
        unordered_map<ll,ll> um;
        unordered_map<ll,ll> um2;
        for(int i=0;i<k;i++){
            cin>>arr[i];
            um[arr[i]]++;
        }
        for(int i=0;i<k;i++){
            cin>>arr2[i];
            um2[arr2[i]]++;
        }
        ll ans = 0;
        for(int i=0;i<k;i++){
            ans+=k-um[arr[i]]-um2[arr2[i]]+1;
        }
        // ll tot = 0;
        // for(int i=0;i<k;i++){
        //    ll val1 = arr[i];
        //    ll val2 = arr2[i];
        //    if(val1==val2)ans+=k-um[val1];
        //    else{
        //        ans += k-(um[val1]+um[val2])+1;
        //    }
        // //    cout<<ans<<" ";
        // }
        cout<<ans/2<<endl;
    }
    return 0;
}