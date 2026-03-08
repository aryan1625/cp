//prefix sum and observation
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
        string a;
        string b;
        cin>>a;
        cin>>b;
        vector<ll> v1(n,0);
        vector<ll> v2(n,0);
        ll val1 = a[0]-'0';
        ll val2 = b[0]-'0';
        if(val1!=val2){
            v1[0]++;
        }
        ll ele = v1[0];
        for(int i=1;i<n;i++){
            v1[i] = v1[i-1];
            if(b[i]!=val2){
                v1[i]++;
            }
            ele+=v1[i];
        }
        v2[0] = ele;
        for(int i=1;i<n;i++){
            v2[i] = v2[i-1];
            if(a[i]!=val1){
                v2[i]++;
            }
            ele+=v2[i];
        }
        cout<<ele<<endl;
        
    }
    return 0;
}