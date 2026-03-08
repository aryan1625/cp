#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
vector<int> maxValue(vector<int>& nums) {
    int n = nums.size();
    vector<int> pref(n,0);
    vector<int> suf(n,INT_MAX);
    pref[0] = nums[0];
    suf[n-1] = nums[n-1];
    for(int i=1;i<n;i++){
        pref[i] = max(pref[i-1],nums[i]);
    }
    for(int i=n-2;i>=0;i--){
        suf[i] = min(suf[i+1],nums[i]);
    }
    vector<int> ans(n,0);
    ans[n-1] = pref[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i] = pref[i];
        if(pref[i]>suf[i+1]){
            ans[i] = ans[i+1];
        }
    }
    return ans;

}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int> ans = maxValue(v);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}