#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        vector<ll> arr(n);
        bool flag = true;
        bool flag2 = false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(flag2)x--;
            if(arr[i]==1){
                if(!flag2){
                    flag2 = true;
                }else{
                    if(x<=0){
                        flag = false;
                    }
                }
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