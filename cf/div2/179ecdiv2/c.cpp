#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }   
        long long int cost = LLONG_MAX;
        for(int i=0;i<n;i++){
            if(i==n-1){
                cost = min(cost, (long long)arr[i] * (n-1));
                continue;
            }
            long long int left = (long long)arr[i] * (i);
            while(i<n-1 && arr[i]==arr[i+1]){
                i++;
            }
            long long int right = (long long)arr[i] * (n-i-1);
            cost = min(cost, left + right);
        }
        cout<<cost<<endl;
    }
    return 0;
}