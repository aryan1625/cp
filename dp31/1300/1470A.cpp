#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> k(n);
        vector<ll> c(m);
        ll ans = 0;
        for(int i=0;i<n;i++){
            cin>>k[i];
            k[i]--;
        }
        set<pair<ll,ll>> st;
        for(int i=0;i<m;i++){
            cin>>c[i];
            st.insert({c[i],i});
        }
        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++){
            v[i].first = c[k[i]];
            v[i].second = k[i];
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            ll val1 = v[i].first;
            ll idx = v[i].second;
            bool flag = false;
            for(auto j: st){
                if(j.first>=val1)break;
                if(j.second<idx && j.first<val1){
                    ans+=j.first;
                    st.erase(j);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans+=val1;
            }
        }
        cout<<ans<<endl;


        

    }
    return 0;
}