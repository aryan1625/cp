#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       ll ans = 0;
       vector<ll> a(n);
       vector<ll> val;
       vector<ll> idx;
       for(int i=0;i<n;i++){
        cin>>a[i];
        if(i+1>a[i]){
            val.push_back(a[i]);
            idx.push_back(i+1);
        }
       }
       int m = val.size();
       for(int i=1;i<m;i++){
        auto it = lower_bound(idx.begin(),idx.end(),val[i]);
        ll ele = it-idx.begin();
        ans+=ele;
       }
       cout<<ans<<endl;

       
    }
    return 0;
}