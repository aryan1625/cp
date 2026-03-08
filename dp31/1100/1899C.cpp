#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        long long int sum = arr[0];
        long long int maxi = sum;
        int par = abs(arr[0])%2;
        for(int i=1;i<n;i++){
            if(abs(arr[i])%2!=par){
                sum+=arr[i];
            }else{
                sum = arr[i];
            }
            if(arr[i]>sum){
                sum = arr[i];
            }
            par = abs(arr[i])%2;
            maxi = max(maxi,sum);
        }
        cout<<maxi<<endl;
    }
    return 0;
}