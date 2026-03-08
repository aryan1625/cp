#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,j,k;
        cin>>n>>j>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(k>1){
            cout<<"Yes"<<endl;
        }else{
            ll val1 = v[j-1];
            ll maxi = *max_element(v.begin(), v.end());
            if(val1 == maxi){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
        
    }
    return 0;
}