//math,dp kind of, greedy
//seperate the rows and columns and then find out for them
#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll solve(map<ll,vector<ll>> &um1){
    ll ans = 0;
    for(auto &it:um1){
        vector<ll> &v1 = it.second;
        ll sz = v1.size();
        if(sz<=1)continue;
        sort(v1.begin(), v1.end());
        ll val1 = 0;
        for(auto i: v1)val1+=i;
        for(int i=0;i<sz;i++){
            val1-= v1[i];
            ans += val1-(sz-i-1)*v1[i];
        }
    }
    return ans;
}
int main(){
    ll n,m;
    cin>>n>>m;
    map<ll,vector<ll>> um1;
    map<ll,vector<ll>> um2;
    vector<vector<ll>> v(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            um1[v[i][j]].push_back(i);
            um2[v[i][j]].push_back(j);
        }
    }
    ll ans = solve(um1) + solve(um2);
    cout<<ans<<endl;
    return 0;
}