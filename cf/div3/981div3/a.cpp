#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){ 
        int n;
        cin>>n;
        // int x = 1;
        // int dis = 0;
        // bool flag = true;
        // while(abs(dis)<=n){
        //     if(flag){
        //         dis = 1-2*x;
        //         flag = false;
        //     }else{
        //         dis = 2*x-1;
        //         flag = true;
        //     }
        //     x++;
        // }
        // if(dis<=0){
        //     cout<<"Kosuke"<<endl;
        // }else{
        //     cout<<"Sakurako"<<endl;
        // }
        if(n&1){
            cout<<"Kosuke"<<endl;
        }else{
            cout<<"Sakurako"<<endl;
        }
    }
    return 0;
}