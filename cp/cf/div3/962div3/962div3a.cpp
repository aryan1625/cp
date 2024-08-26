#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int val = n/4;
        int ele = n%4==0?0:1;
        cout<<val+ele<<endl;
    }
    return 0;
}