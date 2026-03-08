#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll cnt = k;
        ll n1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                n1++;
            }
        }
        ll n0 = n - n1;
        if(2*k>n){
            cout<<"Alice"<<endl;
        }else{
            if(n1<=k){
                cout<<"Alice"<<endl;
            }else{
                cout<<"Bob"<<endl;
            }
        }
        
        
    }
    return 0;
}