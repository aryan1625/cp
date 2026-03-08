#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,w;
        cin>>n>>w;
        // ll ans=  1;
        vector<ll> a(n);
        multiset<ll> ms;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ms.insert(a[i]);
        }
        // sort(a.begin(),a.end());
        ll ans = 1;
        ll wid = w;
        while(!ms.empty()){
            auto it  = ms.upper_bound(wid);
            if(it==ms.begin()){
                ans++;
                wid =w;
            }else{
                it--;
                ll val = *it;
                wid-=val;
                ms.erase(it);
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}