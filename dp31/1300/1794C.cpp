#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<ll> a(n);
       vector<ll> ans(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       //since val,newVal,newVal2 becomes too large we have to use log
       ans[0] = 1;
       ld val = logl(a[0]);
       ld cnt = 1;
       ll idx = 0;
       for(int i=1;i<n;i++){
        cnt++;
        ld newVal  = val + logl(a[i]) - logl(cnt);
        ld newVal2 = newVal + logl(cnt) - logl(a[idx]);
        while(newVal<newVal2){
            cnt--;
            idx++;
            newVal = newVal2;
            newVal2 = newVal + logl(cnt) - logl(a[idx]);
        }
        val = newVal;
        ans[i] = cnt;
       }
       for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
       }
       cout<<endl;
    }
    return 0;
}