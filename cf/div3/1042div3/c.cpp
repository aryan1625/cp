#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> S(n);
        multiset<ll> ms1;
        multiset<ll> ms2;
        ll val1 = 0;
        for(int i=0;i<n;i++){
            cin>>S[i];
            S[i]%=k;
            ms1.insert(S[i]);
        }
        ll val2 = 0;
        vector<ll> T(n);
        for(int i=0;i<n;i++){
            cin>>T[i];
            T[i]%=k;
            ms2.insert(T[i]);
        }
        bool flag= true;
        for(auto it: ms1){
            int val = it;
            ll val2 = k-it;
            auto it2 = ms2.find(val);
            if(it2!=ms2.end()){
                ms2.erase(it2);
                continue;
            }
            auto it3 = ms2.find(val2);
            if(it3!=ms2.end()){
                ms2.erase(it3);
                continue;
            }
            flag = false;
            break;
            
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

        

        
    }
    return 0;
}