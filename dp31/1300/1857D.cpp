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
       vector<ll> b(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       for(int i=0;i<n;i++){
        cin>>b[i];
       }
       vector<ll> c(n);
       ll maxi = INT_MIN;
       for(int i=0;i<n;i++){
        c[i] =  a[i]-b[i];
        maxi = max(maxi,c[i]);
       }
       vector<ll> ans;
       ll cnt = 0;
       for(int i=0;i<n;i++){
        if(c[i]==maxi){
            cnt++;
            ans.push_back(i+1);
        }
       }
       cout<<cnt<<endl;
       for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
       }
       cout<<endl;
    }
    return 0;
}