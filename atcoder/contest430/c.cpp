#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
        ll n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        vector<pair<ll,ll>> v(n+1);
        v[0]= {0,0};
        for(int i=1;i<=n;i++){
            v[i] = v[i-1];
            if(s[i-1]=='a'){
                v[i].first++;
            }else{
                v[i].second++;
            }
        }
        ll ans = 0;
        // ll lastb = -1;
        ll l = 0;
        // ll cnt = 1;
        for(int r=1;r<=n;r++){
            while((l<r)&&(v[r].second-v[l].second>=b)){
                l++;
                // cnt = 1;
            }
            ll low = l,hi = r-1;
            ll cnt = r;
            while(low<=hi){
                ll mid = (low+hi)/2;
                if(v[r].first - v[mid].first < a){
                    hi = mid - 1;
                }else{
                    cnt = mid;
                    low = mid + 1;
                }
            }
            if(cnt!=r)ans+= (cnt - l+1);
        }
        cout<<ans<<endl;
        
    return 0;
}