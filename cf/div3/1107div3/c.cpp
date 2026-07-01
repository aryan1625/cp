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
       string s;
       cin>>s;
       bool zer = 0;
       bool one = 0;
       bool flag = true;
      //  vector<int> arr(n,0);
      string s2 = "";
      s2+=s[0];
       int val = 0;
       for(int i=1;i<n;i++){
         if(s[i]==s[i-1])continue;
         else{
             s2+=s[i];
         }
       }
       if(s2.size()==2)cout<<2<<endl;
       else{
         cout<<1<<endl;
       }
     }

    return 0;
}