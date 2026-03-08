#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
vector<ll> fac(ll k){
    vector<ll> ans;
    for(ll i=1;i*i<=k;i++){
        if(k%i==0){
            ans.push_back(i);
            if(i!=k/i)ans.push_back(k/i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
string transf(string &s,ll val){
    string ans = string(val,'a');
    for(int i=0;i<val;i++){
        ans[i] = s[i%s.size()];
    }
    return ans;
}
//brute force 😭😭😭😭😭
int main(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll beg = 1;
    ll end = n;
    string ans = transf(s,k);
    for(int i=0;i<n;i++){
        string s1 = s.substr(0,i+1);
        string s2 = transf(s1,k);
        if(s2<ans){
            ans = s2;
        }
    }
    cout<<ans<<endl;

    return 0;
}