#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;

//observations
/*
1. A[n]-> fixed so max(A[n-1],A[n]+1);
2. if ith element is largest after all ops , then A[i+1] has to be A[i]-1;
3. so we will iterate through the array and do binary search on the max value it can take
// then we will iterate the array again and check if we can make A[i] as max value



*/
bool solve(vector<ll> &v, ll idx, ll val,ll k){
    // vector<ll> temp = v;
    ll n = v.size();
    ll cnt = val;
    ll tot = 0;
    int i = idx;
    for(i=idx;i<n-1;i++){
        if(v[i]<cnt){
            tot+= (cnt-v[i]);
            cnt--;
        }else{
            break;
        }
    }
    if(i==n-1 && v[i]<cnt)return false;
    if(tot<=k)return true;
    return false;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll maxi = v[n-1];
        for(int i=0;i<n-1;i++){
            //find maxi
            ll st = 0;
            ll end = 1e9;
            ll val = 0;
            while(st<=end){
                ll mid = st+(end-st)/2;
                if(solve(v,i,mid,k)){
                    val = mid;
                    st = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            maxi = max(maxi, val);
        }
        cout<<maxi<<endl;
    }
    return 0;
}