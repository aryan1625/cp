#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int i = 0;
        int j = n-1;
        bool flag = true;
        vector<ll> arr(n,0);
        for(int k=1;k<=n;k++){
            if(flag){
                arr[i++] = k;
            }else{
                arr[j--] = k;
            }
            flag = !flag;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}