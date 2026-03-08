#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
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
        vector<ll> ans;
        ans.push_back(v[0]);
        ans.push_back(v[1]);
        ll sz = 0;
        for(int i=2;i<n;i++){
            int s = ans.size();
            if(ans[sz]>ans[sz+1]){
                if(v[i]<ans[sz+1]){
                    ans.pop_back();
                    sz--;
                }
                sz++;
                ans.push_back(v[i]);
            }else{
                if(v[i]>ans[sz+1]){
                    ans.pop_back();
                    sz--;
                }
                sz++;
                ans.push_back(v[i]);
            }
        }
        ll k = ans.size();
        cout<<k<<endl;
        for(int i=0;i<k;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}