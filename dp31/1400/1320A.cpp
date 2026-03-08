#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
// bj-bi = j-i -> bj-j = bi-i
int main(){
    
        ll n;
        cin>>n;
        vector<ll> v(n);
        vector<ll> v2(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            v2[i] = v[i]-i-1;
        }
        unordered_map<ll,ll> um;
        for(int i=0;i<n;i++){
            um[v2[i]]+=v[i];
        }
        ll maxi = 0;
        for(auto i:um){
            maxi = max(maxi,i.second);
        }
        cout<<maxi<<endl;
    return 0;
}