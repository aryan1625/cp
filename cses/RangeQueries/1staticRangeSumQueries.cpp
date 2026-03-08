#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
//prefix sum
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> pre(n+1,0);
    for(int i=0;i<n;i++){
        pre[i+1] = pre[i]+arr[i];
    }
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<endl;
    }   
    return 0;
}