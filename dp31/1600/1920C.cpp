//observation suppose for factor k of n 
// we check if a1,a1+k,a1+2k.... %m are same or not
// so (a1)%m = (a1+k)%m 
//now subtracting (a1+k)%m from both sides we get
// (a1-a1+k)%m = 0%m
// similarly for (a1+k-a2+k)%m = 0%m
//so we need to check gcd of all such differences
// now for a1,a1+k,a1+2k.... we get gcd = m1
//similaryly for a2,a2+k,a2+2k.... we get gcd = m2
// now we need to check gcd(m1,m2....) = m
// if m!=1 then we can have m as answer
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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll ans = 1;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        ll val = abs(v[0]-v[1]);
        //check for 1
        for(int i=1;i<n-1;i++){
            val = __gcd(val, abs(v[i]-v[i+1]));
        }
        if(val!=1){
            ans++;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                if(i!=n/i){
                    ll ele = abs(v[0]-v[n/i]);
                    for(int j=1;j<n;j++){
                        if((j+n/i)<n){
                            ll val = abs(v[j]-v[j+n/i]);
                            ele = __gcd(ele, val);
                        }
                    }
                    if(ele!=1){
                        ans++;
                    }
                }
                ll ele = abs(v[0]-v[i]);
                for(int j=1;j<n;j++){
                    if(j+i<n){
                        ll val = abs(v[j]-v[j+i]);
                        ele = __gcd(ele, val);
                    }
                }
                if(ele!=1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}