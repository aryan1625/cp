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
       vector<ll> a(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       vector<ll> vec(32,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<32;j++){
            if(((a[i]>>j)&1)==1){
                vec[j]++;
            }
        }
       }
       ll ans = 0;
       for(int j=30;j>=0;j--){
        if(k>=n-vec[j]){
            ans += pow(2,j);
            k = k-n+vec[j];
        }
       }
       if(vec[31]==n)ans+=pow(2,31);
       cout<<ans<<endl;

    }
    return 0;
}