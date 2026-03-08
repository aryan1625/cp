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
        vector<ll> v(n);
        vector<ll> v2;
        set<ll> st;
        for(int i=0;i<n;i++){
            cin>>v[i];
            st.insert(v[i]);
        }
        ll val = v[k-1];
        for(auto it:st){
            v2.push_back(it);
        }
        n = v2.size();
        // ll maxi = 0;
        // for(int i=0;i<n;i++){
        //     maxi = max(maxi, v2[i]);
        // }
        sort(v2.begin(), v2.end());
        // int idx = 0;
        auto it = lower_bound(v2.begin(), v2.end(), val);
        int idx = it - v2.begin();
        bool flag = true;
        ll prev = 0;
        for(int i=idx;i<n-1;i++){
            prev+=v2[i+1]-v2[i];
            if(v2[i]<prev){
                flag = false;
                break;
            }
        }
        // cout<<idx<<" "<<idx2<<endl;
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}