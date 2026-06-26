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
using ld = long double;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
       ll n,a,b;
       cin>>n>>a>>b;
       ld val1 = (ld)b/3;
       ll ans = 0;
       if(val1<a){
        ll qu = n/3;
        ans += qu*b;
        ll rem = n%3;
        ans += min(rem*a,b);
       }else{
        ans = n*a;
       }
       cout<<ans<<endl;
    }
    return 0;
}