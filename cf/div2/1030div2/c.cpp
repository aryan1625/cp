#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
       ll n,k;
       cin>>n>>k;
       vector<ll>a(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       sort(a.begin(),a.end());
       ll ans = 0;
       vector<ll> vec(60,0);
       for(int i=0;i<n;i++){
        for(int j=32;j>=0;j--){
            if(((a[i]>>j)&1)==1){
                ans++;
                vec[j]++;
            }
        }
       }
       vector<ll> pow2v(60);
       for(int i=0;i<60;i++){
        pow2v[i] = (1LL<<i);
       }
       for(int i=0;i<60;i++){
        ll val = n-vec[i];
        ll val2 = k/pow2v[i];
        ll val3 = min(val,val2);
        ans+=val3;
        k-=val3*pow2v[i];
       }
       cout<<ans<<endl;

    }
    return 0;
}