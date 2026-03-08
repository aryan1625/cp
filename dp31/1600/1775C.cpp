#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
//observation - > more number of operands the less the value will get in and 
ll solve(ll n, ll mid){
    ll val = (ll)log2(mid)+1;
    ll ans = -1;
    for(int i=0;i<val;i++){
        if(mid<=n){
            ans = mid;
            return ans;
        }
        if(mid&(1LL<<i)){
            mid = mid & (~(1LL<<i));
        }
    }
    return mid;

}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll left = n;
        ll right = 5e18;
        ll ans = -1;
        while(left<=right){
            ll mid = left+(right-left)/2;
            ll ele = solve(n,mid);
            if(ele==x){
                ans = mid;
                right = mid-1;
            }else if(ele>x){
                left = mid+1;
            }
            else{
                right = mid-1;
            }

        }
        cout<<ans<<endl;
        
        
    }
    return 0;
}