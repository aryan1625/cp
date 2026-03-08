#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll solve(ll n, ll mid){
    ll val = n-mid;
    return (n*(n+1))/2 - (val*(val+1))/2;
}
int main(){
    ll t;
    cin>>t;
    string ans = "";
    while(t--){
        string s;
        cin>>s;
        ll k;
        cin>>k;
        ll n = s.size();
        ll st = 1;
        ll end = n;
        ll val = n;
        while(st<=end){
            ll mid = (st+end)/2;
            if(solve(n,mid)>=k){
                val = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        val--;
        ll rem = k-solve(n,val);

        //remove val
        //count rem 
        ll cnt = 0;
        string sam = "";
        sam+=s[0];
        int i = 1;
        for(i=1;i<n;i++){
            if(cnt>=val)break;
            if(sam.empty() || sam.back()<=s[i]){
                sam+=s[i];
            }else{
                while(sam.back()>s[i] && cnt<val){
                    sam.pop_back();
                    cnt++;
                }
                if(cnt>=val)break;
                sam+=s[i];
            }
        }
        while(i<n)sam+=s[i++];
        ans += sam[rem-1];

    }
    cout<<ans<<endl;
    return 0;
}