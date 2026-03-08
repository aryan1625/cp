#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
   ll n,m;
   cin>>n>>m;
   vector<ll> a(n);
   vector<ll> b(m);
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<m;i++)cin>>b[i];
   sort(a.begin(),a.end());
   if(n==1){
    for(int i=0;i<m;i++) cout<<(a[0]+b[i])<<" ";
    cout<<endl;
    return 0;
   }
   ll gc1 = a[1]-a[0];
   for(int i=2;i<n;i++){
    gc1 = __gcd(gc1,a[i]-a[0]);
   }
   for(int i=0;i<m;i++){
    cout<<__gcd(gc1,a[0]+b[i])<<" ";
   }
   cout<<endl;  
    return 0;
}