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
        vector<ll> d(k);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=0;i<k;i++){
            cin>>d[i];
        }
        sort(v.rbegin(),v.rend());
        sort(d.begin(),d.end());
        int i = 0;
        int j = 0;
        ll sum = accumulate(v.begin(),v.end(),0LL);
        while(i<n && j<k){
            i+=d[j];
            j++;
            if(i>n)break;
            sum-=v[i-1];
        }
        cout<<sum<<endl;
        
    }
    return 0;
}