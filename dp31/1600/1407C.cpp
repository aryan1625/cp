#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    if(n==1){
        cout<<'!'<<endl;
        cout<<1<<endl;
        return 0;
    }
    ll val = 0;
    ll val2 = 1;
    for(int i=0;i<n-1;i++){
        cout<<"? "<<val+1<<" "<<val2+1<<endl;
        ll x1,x2;
        cin>>x1;
        cout<<"? "<<val2+1<<" "<<val+1<<endl;
        cin>>x2;
        if(x1>x2){
            a[val] = x1;
            val = val2;
            val2++;
        }else{
            a[val2] = x2;
            val2++;
        }
    }
    a[val] = n;
    cout<<'!'<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}