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
        sort(v.begin(), v.end());
        //min val jaha end hoti cheeze
        ll mini = 0;
        ll val = 0;
        map<ll,ll>mp;
        map<ll,ll>mp2;
        for(int i=0;i<n;i++){
            if(v[i]>mini){
                val = n-i;
                break;
            }
            if(v[i]==mini)mini++;
            mp[v[i]]++;
        }
        ll cnt = mini;
        vector<ll> ans(n+1,1);
        ll idx = n-mini;
        for(int i=n-mini+1;i<=n;i++){
            ans[i] = cnt;
            cnt--;
        }
        for(auto i:mp){
            mp2[i.second]++;
        }
        // for(int i=1;i<n;i++){
        //     mp2.lower_bound(i);

        // }

        for(int i=1;i<=idx;i++){
            // cout<<mp2[i]<<endl;
            ans[i] = ans[i-1]+mp2[i];
        }
        for(int i=0;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}