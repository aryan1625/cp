#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
       ll n,k;
       cin>>n>>k;
       string s;
       for(int i=0;i<k;i++){
        s+='1';
       }
       for(int i=k;i<n;i++){
        s+='0';
       }
       cout<<s<<endl;

       
       

    }
    return 0;
}