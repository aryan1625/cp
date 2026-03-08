#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
bool solve(ll mid, vector<ll> &v2){
    ll left = 0;
    ll want = 0;
    for(int i=0;i<v2.size();i++){
        if(v2[i]>=mid){
            want+=v2[i]-mid;
        }else{
            //we will do this instead of just adding because of case
            //for example when timer 3 works but at timer2 one worker is free
            // so it will take 2 hours to finish making the total 4hours which is not 
            //correct so we will take the difference divided by 2 instad of just 
            //adding the difference and then multiplying by 2 in the final 
            // left+=mid-v2[i];-> wrong
            left+=(mid-v2[i])/2;
        }
    }
    // return left>=2*want -> wrong
    return left>=want;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> v(m);
        vector<ll> v2(n);
        for(int i=0;i<m;i++){
            cin>>v[i];
            v2[v[i]-1]++;
        }
        // sort(v2.begin(), v2.end());
        ll ans= 2e5+1;
        //bs
        ll st = 1;
        ll end = 2e5+1;
        while(st<=end){
            ll mid = st+(end-st)/2;
            if(solve(mid,v2)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        cout<<ans<<endl;
        

        
    }
    return 0;
}