#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,k; 
        cin>>x>>y>>k;
        int val = min(x,y);
        cout<<0<<" "<<0<<" "<<val<<" "<<val<<endl;
        cout<<0<<" "<<val<<" "<<val<<" "<<0<<endl;
    }
    return 0;
}