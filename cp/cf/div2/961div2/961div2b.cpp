#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        // int n;
        // long long int m;
        // cin>>n>>m;
        // vector<int> arr(n);
        // for(int i=0;i<n;i++){
        //     cin>>arr[i];
        // }
        // sort(arr.begin(),arr.end());
        // long long int maxi = 0;
        // if(arr[0]>m){
        //     cout<<0<<endl;
        //     continue;
        // }
        // long long int val = arr[0]; 
        // m-=arr[0];
        // int left = 0;
        // int fix = m;
        // for(int i=1;i<n;i++){
        //     val += arr[i];
        //     while(arr[i]-arr[left]>1 || m<arr[i]){
        //         val -= arr[left];
        //         m += arr[left];
        //         left++;
        //     }
        //     m-=arr[i];
        //     // cout<<left<<endl;
        //     maxi = max(val,maxi);
        // }
        // cout<<maxi<<endl;
        int n;
        long long int m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        long long int maxi = 0;
        long long int val = 0;
        long long int c = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            val += arr[right];
            c += arr[right];
            
            // Ensure that we don't exceed the budget and the petal difference condition
            while (c > m || (arr[right] - arr[left] > 1)) {
                val -= arr[left];
                c -= arr[left];
                left++;
            }
            
            // Update the maximum petals we can get
            maxi = max(maxi, val);
        }
        
        cout << maxi << endl;
    // return 0;
    }
    return 0;
}