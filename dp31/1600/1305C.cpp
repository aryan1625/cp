#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
//wtf! bro pigeon hole bkc
int main(){
   
        ll n,m;
        cin>>n>>m;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(m==1){
            cout<<0<<endl;
            return 0;
        }
        if(n>m){
            cout<<0<<endl;
            return 0;
        }
        sort(v.begin(),v.end());
        ll val1 =1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
               val1 = (val1*(v[i]-v[j]))%m;
            }
        }
        cout<<val1%m<<endl;
        
        

    return 0;
}