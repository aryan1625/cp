#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
vector<vector<ll>> SparseTable(vector<ll> &arr){
    int n = arr.size();
    //calculate length of binary representation
    ll len = 32- __builtin_clz(n);
    vector<vector<ll>> st(n,vector<ll>(len));
    //initialize first column of sparse table
    for(int i=0;i<n;i++){
        st[i][0] = arr[i];
    }
    //loop
    //j->0 to (1<<j)<=n
    //i->0 to i+(1<<j)<=n
    // gcd/max/min of i,j-1 and i+(1<<(j-1)),j-1
    for(int j = 1; (1<<j)<=n; j++){
        for(int i=  0; i + (1 << j) <= n;i++){
            st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    return st;
}
ll query(ll l, ll r, vector<vector<ll>>& st){
    if (l > r || l < 0) return LLONG_MIN;
    ll len = 31- __builtin_clz(r-l+1);
    return max(st[l][len],st[r-(1<<len)+1][len]);
}
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
        
    }
    return 0;
}