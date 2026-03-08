#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
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
        ll mini = 1e9;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(v[i]>=mini*2){
                flag = false;
                break;
            }
            mini = min(v[i],mini);
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}