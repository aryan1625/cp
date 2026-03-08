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
        vector<vector<ll>> v(n);
        for(int i=0;i<n;i++){
            v[i].resize(3);
            cin>>v[i][0]>>v[i][1]>>v[i][2];
        }
        sort(v.begin(),v.end());
        ll maxi = k;
        set<ll> st;
        st.insert(k);
        for(int i=0;i<n;i++){
            ll l1 = v[i][0];
            ll r1 = v[i][1];
            ll val = v[i][2];
            auto it1 = st.lower_bound(l1);
            auto it2 = st.lower_bound(r1);
            if(it1==st.end())continue;
            if(it1!=it2){
                maxi = max(maxi,val);
                st.insert(val);
            }else{
                ll ele = *it1;
                if(ele>=l1 && ele<=r1){
                    maxi = max(maxi,val);
                    st.insert(val);
                }
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}