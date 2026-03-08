#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
ll fact(ll n){
    if(n<=1)return 1;
    ll val = 1;
    for(int i=1;i<=n;i++){
        val = ((val%mod)*(i%mod))%mod;
    }
    return val%mod;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n =s.size();
        ll ans1 = 0;
        ll ans2= 1;
        ll cnt = 1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }else{
                ans2 = ((ans2%mod)*(cnt%mod))%mod;
                ans1+=cnt-1;
                cnt = 1;
            }
        }
        ans2 = ((ans2%mod)*(cnt%mod))%mod;
        ans1+=cnt-1;
        ans2 = ((ans2%mod)*(fact(ans1)%mod))%mod;
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}