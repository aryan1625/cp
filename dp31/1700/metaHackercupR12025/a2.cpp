#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
bool solve(ll mid,vector<ll>& v){
    ll n = v.size();
    queue<ll> q;
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++){
        if(v[i]<=mid){
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty()){
        ll idx = q.front();
        q.pop();
        if(idx>0 && abs(v[idx-1]-v[idx])<=mid && !vis[idx-1]){
            vis[idx-1]=1;
            q.push(idx-1);
        }
        if(idx<n-1 && abs(v[idx+1]-v[idx])<=mid && !vis[idx+1]){
            vis[idx+1]=1;
            q.push(idx+1);
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i])return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("a2actual.txt", "r", stdin);
    freopen("a2output2.txt", "w", stdout);
    ll t;
    cin>>t;
    ll cnt= 1;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        ll end = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            end = max(end,v[i]);
        }
        for(int i=0;i<n-1;i++){
            end = max(end,abs(v[i+1]-v[i]));
        }
        ll st = 0;
        ll ans = 1e9;
        while(st<=end){
            ll mid = st+(end-st)/2;
            if(solve(mid,v)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
    return 0;
}