    #include<bits/stdc++.h>
    using namespace std;
    int mod = 998244353;
    using ll = long long ;
    using ld = long double ;
    ll safe_mod(ll x,ll mod1){
        if(mod1==0)return 0;
        return ((x%mod1)+mod1)%mod1;
    }
    int main(){
        ll t;
        cin>>t;
        while(t--){
            ll n,x;
            cin>>n>>x;
            set<ll> s;
            ll val1 = n-x;
            if((val1&1)==0){
                // val1/=2;
                for(ll i=1;i*i<=val1;i++){
                    if(val1%i==0){
                        ll k1 = i;
                        ll k2 = val1/i;
                        if(k1%2==0){
                            s.insert((k1+2)/2);
                        }
                        if(k2%2==0){
                            s.insert((k2+2)/2);
                        }
                    }
                }
            }
            ll val2 = n+x-2;
            if((val2&1)==0){
                
                for(ll i=1;i*i<=val2;i++){
                    if(val2%i==0){
                        ll k1 = i;
                        ll k2 = val2/i;
                        if(k1%2==0){
                            s.insert((k1+2)/2);
                        }
                        if(k2%2==0){
                            s.insert((k2+2)/2);
                        }
                    }
                }
            }
            ll cnt = 0;
            for(auto it:s){
                if(it>=x)cnt++;
            }
            cout<<cnt<<endl;
        }
        return 0;
    }