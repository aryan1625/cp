#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        bool flag  = true;
        if(c>=a){
            if(d<b)flag = false;
        }
        if(flag){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
        
    return 0;
}