#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using ll = long long;
using namespace std;
// void generate(ll a,ll b,ll c,ll st,ll num,set<ll> &values){
//    if(c==0){
//       values.insert(num);
//       return;
//    }
//    num = num*10;
//    generate(a,b,c-1,st,num+a,values);
//    if(c!=st || b!=0 ){
//       generate(a,b,c-1,st,num+b,values);
//    }
//    return ;
// }
// bool check(ll x) {
//     int mask = 0;
//     while(x){
//         mask |= 1<<(x % 10);
//         if(__builtin_popcount(mask) > 2)return false;
//         x/=10;
//     }
//     return true;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   //  set<ll> values;
   //  for(int i=2;i<=9;i++)values.insert(i);
   //  for(int a=1;a<=9;a++){
   //    for(int b=0;b<=9;b++){
   //       for(int c=2;c<=8;c++){
   //          int num = 0;
   //          generate(a,b,c,c,num,values);
   //       }
   //    }
   // }

    ll t;
    cin>>t;
    while(t--){
       ll x;
       cin>>x;
       ll a = (ll)log10(x)+1;
      //  cout<<"x "<<x<<endl;
      //  cout<<"a "<<a<<endl;
       ll y = pow(10,a)+1;
       cout<<y<<endl;
      //  for(auto it=values.begin();it!=values.end();it++){
      //     ll val= *it * x;
      //     if(check(val)){
      //       y = *it;
      //       break;
      //     }
      //  }
      //  if(y!=1){
      //    cout<<y<<endl;
      //  }
     }

    

    return 0;
}