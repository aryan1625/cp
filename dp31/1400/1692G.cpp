//greedy maths
#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<ld> v1(n);
        for(int i=0;i<n;i++){
            v1[i] = (ld)log2(v[i])+i;
        }
        ll cnt = 0;
        ll ans = 0;
        for(int i=0;i<n-1;i++){
            if(cnt>=k){
                ans++;
            }
            if(v1[i]<v1[i+1]){
                cnt++;
            }else{
                cnt = 0;
            }
        }
        if(cnt>=k)ans++;
        cout<<ans<<endl;
        
    }
    return 0;
}