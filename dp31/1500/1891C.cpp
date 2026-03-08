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
        int i = 0;
        int j = n-1;
        ll ans = 0;
        ll val = 0;
        while(i<j){
            if(val+v[i]<v[j]){
                ans+=v[i];
                val+=v[i];
                i++;
            }else{
                ll ele = v[j]-val;
                ans+=ele+1;
                val = 0;
                v[i] -= ele;
                if(v[i] == 0) i++;
                j--;
            }
        }
        if(i==j){
            ll ele = v[i]-val;
            if(v[i]==1){
                ans+=1;
            }else{
                ans+=(ele+3)/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}