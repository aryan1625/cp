#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
bool solve(ll st, ll end,vector<ll>& val){
    ll cnt = 0;
    for(int i=0;i<val.size();i++){
       if(val[i]>=st && val[i]<=end)cnt++;
    }
   if(cnt&1)return true;
   return false;


}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll st = 1;
        ll end = n;
        while(st<end){
            ll mid = st+(end-st)/2;
            cout<<"? "<<st<<" "<<mid<<endl;
            vector<ll> val(mid-st+1);
            for(int i=0;i<mid-st+1;i++){
                cin>>val[i];
            }
            if(solve(st,mid,val)){
                end = mid;
            }else{
                st = mid+1;
            }
        }
        cout<<"! "<<st<<endl;
        
    }
    return 0;
}