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
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        ll ans = 0;
        vector<pair<ll,ll>> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j+1]<a[j]){
                    vec.push_back({1,j+1});
                    swap(a[j],a[j+1]);
                    ans++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(b[j+1]<b[j]){
                    vec.push_back({2,j+1});
                    swap(b[j],b[j+1]);
                    ans++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                ans++;
                vec.push_back({3,i+1});
                swap(a[i],b[i]);
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<ans;i++){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }


        
    }
    return 0;
}