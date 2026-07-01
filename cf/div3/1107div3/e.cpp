#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <functional>
using ll = long long;
using namespace std;
ll solve(vector<vector<ll>> &arr,ll u){
    ll n = arr[u].size();
    vector<ll> nums(n);
    vector<ll> suf1(n);
    vector<ll> mulsuf1(n,0);
    for(int i=0;i<n;i++){
        nums[i] = arr[u][i];
        // cout<<nums[i]<<" ";
    }
    // cout<<endl;
    suf1 = nums;
    ll ans = 0;
    for(int i=n-1;i>0;i--){
        if(i!=n-1){
            suf1[i] += suf1[i+1];
        }
        ll ele = suf1[i]*nums[i-1];
        ans += ele;
        mulsuf1[i] = ele;
    }
    for(int i=n-1;i>1;i--){
        if(i!=n-1){
            mulsuf1[i] += mulsuf1[i+1];
        }
        ll ele = mulsuf1[i]*nums[i-2];
        ans += ele;
    }
    return ans;

}
vector<vector<ll>> getComponentSizes(vector<vector<ll>> &adj) {
    int n = adj.size() - 1;

    vector<ll> parent(n + 1, 0);
    vector<ll> subtree(n + 1, 1);

    function<void(ll,ll)> dfs = [&](ll u, ll p) {
        parent[u] = p;
        subtree[u] = 1;

        for (ll v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            subtree[u] += subtree[v];
        }
    };

    dfs(1, 0);

    vector<vector<ll>> comp(n + 1);

    for (ll u = 1; u <= n; u++) {
        for (ll v : adj[u]) {
            if (v == parent[u]) {
                // Parent side
                comp[u].push_back(n - subtree[u]);
            } else {
                // Child side
                comp[u].push_back(subtree[v]);
            }
        }
    }

    return comp;
}
bool isPs(ll num){
    ll a = sqrtl(num);
    return a*a==num;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
       ll n;
       cin>>n;
       vector<ll> val(n+1);
       vector<vector<ll>> arr(n+1);
       for(int i=1;i<=n;i++){
           cin>>val[i];
        }
        for(int i=0;i<n-1;i++){
            ll u,v;
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        vector<vector<ll>> comp = getComponentSizes(arr);
    //    vector<ll> num(n+1,0);
    //    for(int i=1;i<=n;i++){
    //     num[i] = arr[i].size();
    //    }
       ll ans = 0;
       for(int i=1;i<=n;i++){
        if(isPs(val[i])){
            ll ele = solve(comp,i);
            // cout<<"i "<<i<<" ele "<<ele<<endl;
            ans += ele;
        }
       }
       cout<<ans<<endl;
     }

    

    return 0;
}