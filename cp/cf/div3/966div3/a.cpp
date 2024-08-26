#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a = log10(n);
        if(n<=101){
            cout<<"No"<<endl;
            continue;
        }
        if(int(n/pow(10,a))==1 && int(n/pow(10,a-1))==10){
            if(a>2 && int(n/pow(10,a-2))<=100){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}