#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
//comparison function 
//true if a is big, false otherwise
bool compareS(string &a,string &b){
    int n1 = a.size();
    int n2 = b.size();
    if(n1>n2)return true;
    if(n1<n2)return false;
    return a>=b;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        //number of leading zeros matter the most 
        ll ans = 0;
        vector<ll> vec;
        for(int i=0;i<n;i++){
            string s= to_string(v[i]);
            ll sz = s.size();
            ans+=sz;
            ll cnt = 0;
            while(!s.empty() && s.back()=='0'){
                s.pop_back();
                cnt++;
            }
            if(cnt!=0)vec.push_back(cnt);

        }
        sort(vec.begin(),vec.end());
        ll eve = 0;
        ll odd = 0;
        for(int i=0;i<vec.size();i++){
            if(i&1){
                odd+=vec[i];
            }else{
                eve+=vec[i];
            }
        }
        if(eve>=odd){
            ans-=eve;
        }else{
            ans-=odd;
        }
        if(ans>=m+1){
            cout<<"Sasha"<<endl;
        }else{
            cout<<"Anna"<<endl;
        }
        

        
        
    }
    return 0;
}