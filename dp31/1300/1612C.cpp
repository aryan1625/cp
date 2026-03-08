#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
       ll k,x;
       cin>>k>>x;
       ll ele = k*k;
       if(ele<=x){
        cout<<2*k-1<<endl;
        continue;
       }
       ll ans = 0;
       ll val1 = (k*(k+1))/2;
       if(x<=val1){
        ll val2 = sqrt(2*x);
        ll val3 = (val2*(val2+1))/2;
        if(x<=val3){
            ans = val2;
        }else{
            ans = val2+1;
        }
       }else{
        x-=val1;
        ll val2 = k*(k-1) - 2*x;
        ll val3 = sqrt(val2);
        ll val4 = val3*(val3+1);
        if(val4<=val2){
            ans = 2*k-val3-1;
        }else{
            ans = 2*k-val3;
        }
       }
       cout<<ans<<endl;
       
       

    }
    return 0;
}