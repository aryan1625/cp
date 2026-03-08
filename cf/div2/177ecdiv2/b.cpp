#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k,x;
        cin>>n>>k>>x;
        long long int ans = 0;
        long long int sum = 0;
        vector<long long int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        long long int ele = x/sum;
        long long int val = x%sum;
        // cout<<"ele: "<<ele<<" "<<"val: "<<val<<" "<<endl;
        if(ele>k || (ele==k && val>0)){
            cout<<0<<endl;
            continue;
        }
        int i = n-1;
        for(i=n-1;i>=0;i--){
           if(val<=0)break;
           val-=arr[i];
        }
        cout<<n*(k-ele-1)+i+2<<endl;

    }
    return 0;
}