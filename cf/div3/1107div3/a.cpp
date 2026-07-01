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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
       ll x,y;
       cin>>x>>y;
       if(x<y){
         cout<<"NO"<<endl;
         continue;
       }
       ll val = x/y;
       if(val*y==x){
         cout<<"YES"<<endl;
       }else{
         cout<<"NO"<<endl;
       }

     }

    

    return 0;
}