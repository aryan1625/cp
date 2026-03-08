//ternary search - unimodal functions - hill or valley
// we will use trnary search on double !!!!
#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ld solve(ld mid, vector<ll> &v, vector<ll> &tim){
    int n = v.size();
    ld maxi = 0;
    for(int i=0;i<n;i++){
        ld ele = abs(mid-v[i])+tim[i];
        maxi = max(maxi,ele);
    }
    return maxi;
}
// we have to find x such that the maximum time for all i's is minimised!!
// we will use ternary search for double
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        vector<ll> tim(n);
        // ld st = 1e9;
        // ld end = -1e9;

        ld st = 1e9;
        ld end = -1e9;
        for(int i=0;i<n;i++){
            cin>>v[i];
            st = min(st,(ld)v[i]);
            end = max(end,(ld)v[i]);
        }
        for(int i=0;i<n;i++){
            cin>>tim[i];
            // v[i]-=tim[i];
            // st = min(st,(ld)v[i]-tim[i]);
            // end = max(end,(ld)v[i]+tim[i]);
        }
        // cout<<fixed<<setprecision(10)<<(st+end)/2.0<<endl;

        for(int i=0;i<100;i++){
            ld mid1 = st+(end-st)/3;
            ld mid2 = end-(end-st)/3;
            ld val1 = solve(mid1,v,tim);
            ld val2 = solve(mid2,v,tim);
            if(val1<val2){
                end = mid2;
            }else{
                st = mid1;
            }
        }
        cout<<fixed<<setprecision(10)<<st<<endl;
        
        
    }
    return 0;
}