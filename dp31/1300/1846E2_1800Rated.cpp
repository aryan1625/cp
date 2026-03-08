#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
// void createMap(set<ll> &st){
//     int i = 2;
//     for(int i=2;i<=1000;i++){
//         ll val2 = i*i;
//         ll val = 1+i+i*i;
//         st.insert(val);
//         while(val<=1e6){
//             val2 = val2*i;
//             val+=val2;
//             st.insert(val);
//         }
//     }
//     return ;
// }
int main(){
    int t;
    cin>>t;
    // set<ll>st;
    // createMap(st);
    // for(auto i:st){
    //     cout<<i<<" ";
    // }
    while(t--){
       ll n;
       cin>>n;
       //we have to take the rth root of n and floor that 
       //r will go from 2 to 64
       bool flag = false;
       for(int i=2;i<70;i++){   
        ll cur = pow(n,1.0/(i+0.0));
        if(cur<2)break;
        ll sums = 1;
        ll powers = 1;
        for(int j=1;j<=i;j++){
            powers*=cur;
            sums+=powers;
        }
        if(sums==n){
            flag = true;
            break;
        }
       }
       if(flag){
        cout<<"yes"<<endl;
       }else{
        cout<<"no"<<endl;
       }

       
    }
    return 0;   
}