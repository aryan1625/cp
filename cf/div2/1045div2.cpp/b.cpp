#include<bits/stdc++.h>
#include <numeric>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;

int main(){
    vector<ll> prime;
    for(int i=2;i<=100;i++){
        bool flag = true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag = false;
                break;
            }
        }
        if(flag)prime.push_back(i);
    }
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll val = v[0];
        for(int i=1;i<n;i++){
            val = __gcd(val,v[i]);
        }
        if(val>1){
            for(int i=0;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        vector<ll> ans = v;
        for(int i=0;i<prime.size();i++){
            if(k%prime[i]==0)continue;
            ll ele = k%prime[i];
            vector<ll> temp(prime[i],0);
            unordered_map<ll,ll> um;
            temp[0] = ele;
            um[ele] = 1;
            for(int j=1;j<prime[i];j++){
                temp[j] = (temp[j-1]+ele)%prime[i];
                um[temp[j]] = j+1;
            }
            for(int j=0;j<n;j++){
                ll ele2 = ans[j]%prime[i];
                if(ele2==0)continue;
                ll ele3 = prime[i]-ele2;
                ans[j] = ans[j]+(um[ele3])*k;
            }
            break;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        // // ans = v;
        // if(k&1){
        //     for(int i=0;i<n;i++){
        //         if(ans[i]&1){
        //             ans[i]+=k;
        //         }
        //     }
        //     for(int i=0;i<n;i++){
        //         cout<<ans[i]<<" ";
        //     }
        //     cout<<endl;
        // }else{
        //     ll ele = k%3;
        //     for(int i=0;i<n;i++){
        //         ll ele2 = ans[i]%3;
        //         if(ele2==0)continue;
        //         if(ele2==ele){
        //             ans[i] = ans[i]+2*k;
        //         }else{
        //             ans[i] = ans[i]+k;
        //         }
        //     }
        //     for(int i=0;i<n;i++){
        //         cout<<ans[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
    }
    return 0;
}