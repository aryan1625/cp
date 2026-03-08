#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        int left = 0;
        int right = n-1;
        while(left<right){
            if(arr[left]+arr[right]>k){
                right--;
            }else if(arr[left]+arr[right]==k){
                ans++;
                left++;
                right--;
            }else{
                left++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}