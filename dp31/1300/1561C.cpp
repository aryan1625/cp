#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> a(n);
        for(int i=0;i<n;i++){
            ll k;
            cin>>k;
            for(int j=0;j<k;j++){
                ll val2;
                cin>>val2;
                a[i].push_back(val2);
            }
        }
        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++){
            int m = a[i].size();
            ll val = 0;
            for(int j=m-1;j>=0;j--){
                if(a[i][j]>=val){
                    val=a[i][j]+1;
                }
                val--;
            }
            v[i].first=val+1;
            v[i].second=val+m+1;
        }        
        sort(v.begin(),v.end(),[](pair<ll,ll> &a1,pair<ll,ll> &b1){
            return a1.first==b1.first?a1.second>b1.second:a1.first<b1.first;
        });
        // for(int i=0;i<n;i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        ll ans = v[0].first;
        for(int i=1;i<n;i++){
            ll prev = v[i-1].second;
            if(prev<v[i].first){
                ans+=v[i].first-v[i-1].second;
            }else{
                v[i].second += prev-v[i].first;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}