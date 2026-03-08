#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> diff;
    for(int i=0;i<n-1;i++){
        diff.push_back(v[i+1]-v[i]);
    }
    sort(diff.begin(),diff.end());
    ll ans = 0;
    for(int i=0;i<n-k;i++){
        ans+=diff[i];
    }
    cout<<ans+k<<endl;
    return 0;
}