#include<bits/stdc++.h>
using namespace std;
int dis(vector<int> &arr){
    int n = arr.size();
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            ans++;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        

    }
    return 0;
}