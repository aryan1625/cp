#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int maxi = LLONG_MIN;
        vector<long long int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        maxi = max(maxi,accumulate(arr.begin(),arr.end(),0LL));
        vector<long long int> nums1;
        while(n>1){
            for(int i=0;i<n-1;i++){
                nums1.push_back(arr[i+1]-arr[i]);
            }
            long long int val = accumulate(nums1.begin(),nums1.end(),0LL);
            maxi = max(maxi,abs(val));
            for(int i=0;i<n-1;i++){
                arr[i] = nums1[i];
            }
            nums1.clear();
            n--;
        }
        cout<<maxi<<endl;
    }
    return 0;
}