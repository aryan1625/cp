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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<ll> vec;
        for(int i=0;i<n;i++){
            if(v[i]==1){
                int cnt = 0;
                while(i<n && v[i]==1){
                    i++;
                    cnt++;
                }
                i--;
                vec.push_back(cnt*-1);
            }else{
                int cnt = 0;
                while(i<n && v[i]==0){
                    i++;
                    cnt++;
                }
                i--;
                vec.push_back(cnt);
            }
        }
        ll ans = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]>0){
                int val = vec[i]+1;
                ans += (val/(k+1));
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}