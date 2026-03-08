#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        vector<ll> pre(n+1,0);
        vector<ll> neg(n+1,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
            pre[i+1] = pre[i];
            neg[i+1] = neg[i];
            if(abs(v[i])==2)pre[i+1]++;
            if(v[i]<0)neg[i+1]++;
            if(v[i]==0){
                pre[i+1] = 0;
                neg[i+1] = 0;
            }
        }
        ll maxi = 0;
        ll first = 0;
        ll second = 0;
        ll beg = 0;
        ll end = n;
        for(int i=1;i<=n;i++){
            if(v[i-1]==0){
                first = i;
                second = i;
                continue;
            }
            if(neg[i]==1 && second==first){
                second = i;
            }
            if(neg[i]&1){
                maxi = max(maxi,pre[i]-pre[second]);
            }else{
                maxi = max(maxi,pre[i]-pre[first]);
            }
        }
        first = 0;
        second = 0;
        for(int i=1;i<=n;i++){
            if(v[i-1]==0){
                first = i;
                second = i;
                continue;
            }
            if(neg[i]==1 && second==first){
                second = i;
            }
            if(neg[i]&1){
                if(pre[i]-pre[second]==maxi){
                    beg = second;
                    end = n-i;
                    break;
                }
            }else{
               if(pre[i]-pre[first]==maxi){
                    beg = first;
                    end = n-i;
                    break;
                }
            }
        }
        cout<<beg<<" "<<end<<endl;


    }
    return 0;
}