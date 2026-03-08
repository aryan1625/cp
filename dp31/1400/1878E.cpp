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
        vector<vector<ll>> freq(n+1,vector<ll>(31,0));
        for(int i=0;i<n;i++){
            cin>>v[i];
            // freq[i+1] = freq[i];
            for(int j=0;j<31;j++){
                freq[i+1][j] = freq[i][j];
                if(((v[i]>>j)&1)==1){
                    freq[i+1][j]++;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     ll ele = 0;
        //     for(int j=0;j<31;j++){
        //         if(freq[i+1][j]==i+1){
        //             ele = ele + (1LL<<j);
        //         }
        //     }
        //     cout<<ele<<" ";
        // }
        ll q;
        cin>>q;
        vector<pair<ll,ll>> vec(q);
        //l and k
        for(int i=0;i<q;i++){
            cin>>vec[i].first>>vec[i].second;
        }
        for(int i=0;i<q;i++){
            ll st = vec[i].first;
            ll l = st;
            ll k = vec[i].second;
            ll end = n;
            ll ans = -1;
            while(st<=end){
                ll mid = st+(end-st)/2;
                ll ele = 0;
                for(int j=0;j<31;j++){
                    if((freq[mid][j]-freq[l-1][j])==(mid-l+1)){
                        ele = ele + (1LL<<j);
                    }
                }
                // if(mid==st){
                //     ele = v[st-1];
                // }
                if(ele>=k){
                    // cout<<i<<" ele: "<<ele<<" mid: "<<mid<<endl;
                    ans = mid;
                    st= mid+1;
                }else{
                    end = mid-1;
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}