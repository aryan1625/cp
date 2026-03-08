#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
void createMap(set<ll> &st){
    int i = 2;
    for(int i=2;i<=1000;i++){
        ll val2 = i*i;
        ll val = 1+i+i*i;
        st.insert(val);
        while(val<=1e6){
            val2 = val2*i;
            val+=val2;
            st.insert(val);
        }
    }
    return ;
}
int main(){
    int t;
    cin>>t;
    set<ll>st;
    createMap(st);
    // for(auto i:st){
    //     cout<<i<<" ";
    // }
    while(t--){
       int n;
       cin>>n;
       if(st.find(n)!=st.end()){
        cout<<"Yes"<<endl;
       }else{
        cout<<"No"<<endl;
       }
       
    }
    return 0;   
}