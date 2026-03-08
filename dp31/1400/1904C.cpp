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
        ll mini = LLONG_MAX;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            mini = min(mini,v[i]);
        }
        if(k>=3){
            cout<<0<<endl;
        }else{
            sort(v.begin(),v.end());
            vector<ll> v2;
            for(int i=0;i<n-1;i++){
                ll val1 = abs(abs(v[i+1]-v[i]));
                mini = min(val1,mini);
                v2.push_back(val1);
            }
            if(k==1){
                cout<<mini<<endl;
                continue;
            }
            set<ll> st;
            ll sz = v2.size();
            for(int i=0;i<sz;i++){
                ll ele = v2[i];
                st.insert(ele);
                for(int j=i+1;j<sz;j++){
                    ele+=v2[j];
                    st.insert(ele);
                }
            }
            for(auto i: st){
                auto it = lower_bound(v.begin(),v.end(),i);
                if(it!=v.end()){
                    mini = min(mini,abs(*it-i));
                }
                if(it!=v.begin()){
                    it--;
                    mini = min(mini,abs(*it-i));
                }
            }
            cout<<mini<<endl;
        }
        
    }
    return 0;
}