#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<pair<ll,ll>> vec(m);
    for(int i=0;i<m;i++){
        ll val1,val2;
        cin>>val1>>val2;
        vec[i] = {val1,val2};
    }
    //abc
    //acb
    //bac
    //bca
    //cab
    //cba
    vector<vector<ll>> pre(6,vector<ll>(n+1,0));
    string s2 = "abc";
    ll cnt = 0;
    do{
        for(int i=1;i<=n;i++){
            pre[cnt][i] = pre[cnt][i-1];
            if(s[i-1]!=s2[(i-1)%3])pre[cnt][i]++;
        }
        cnt++;
    }while(next_permutation(s2.begin(),s2.end()));
    vector<ll> ans(m,0);
    for(int i=0;i<m;i++){
        ll l = vec[i].first;
        ll r = vec[i].second;
        ll maxi = 1e9;
        for(int j=0;j<6;j++){
            maxi = min(maxi,pre[j][r]-pre[j][l-1]);
        }
        ans[i] = maxi;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}