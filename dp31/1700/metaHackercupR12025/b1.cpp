#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("b1actual.txt", "r", stdin);
    freopen("b1output2.txt", "w", stdout);
    ll t;
    cin>>t;
    ll cnt = 1;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        vector<ll> ans(2*n,1);
        ans[2*n-1] = b;
        cout<<"Case #"<<cnt<<": ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        cnt++;
    }
    return 0;
}