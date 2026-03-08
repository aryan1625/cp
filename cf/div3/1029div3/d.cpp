#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
using ld = long double;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ld b = ld((2*arr[0]-arr[1]))/(n+1);
        ll val2 = ll(b);
        if(b!=val2 || b<0){
            cout<<"No"<<endl;
            continue;
        }
        ll a = arr[0]-val2*n;
        if(a<0){
            cout<<"No"<<endl;
            continue;
        }
        bool flag = true;
        for(int i=2;i<n;i++){
            ll ele = arr[i]-(i+1)*a-(n-i)*b;
            if(ele!=0){
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