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
       ll n;
       cin>>n;
       vector<ll> a(n);
       vector<ll> b(n);
       for(int i=0;i<n;i++){
          cin>>a[i];
       }
       for(int i=0;i<n;i++){
          cin>>b[i];
       }
       vector<ll> arr(n,0);
         for(int i=0;i<n;i++){
            arr[i] = b[i]-a[i];
         }
         ll val = 0;
         bool flag = true;
         for(int i=0;i<n;i++){
            val+=arr[i];
            if(val<0){
                flag = false;
                break;
            }
         }
         if(flag)cout<<"YES"<<endl;
         else {
            cout<<"NO"<<endl;
         }
     }

    

    return 0;
}