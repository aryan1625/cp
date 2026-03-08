#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        vector<ll> v(n);
        multiset<ll> st;
        for(int i=0;i<n;i++){
            cin>>v[i];
            st.insert(v[i]);
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i=0;i<n;i++){
            auto it1 = st.lower_bound(c);
            if(it1 == st.end()){
                it1--;
            }
            else if(*it1>c){
                if(it1==st.begin()){
                    ans = (ll)st.size();
                    break;
                }
                it1--;
            }
            multiset<ll> newst;
            ll val = *it1;
            bool flag = 0;
            for(auto it:st){
                if(it==val && !flag){
                    flag = 1;
                    continue;
                }
                newst.insert(2*it);
            }
            st = newst;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}