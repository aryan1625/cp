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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll l = -1;
        ll r = -1;
        for(int i=0;i<n;i++){
            if(v[i]==n){
                l = i;
                r = i;
                break;
            }
        }
        bool flag = true;
        ll cnt = n-1;
        while(cnt>0){
            if(l>0 && v[l-1]==cnt){
                l--;
                cnt--;
                continue;
            }else if(r<n-1 && v[r+1]==cnt){
                r++;
                cnt--;
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}