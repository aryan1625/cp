#include<bits/stdc++.h>
using namespace std;
long long int solve(vector<int>& arr,int k){
    int n = arr.size();
    long long int maxi = 0;
    long long int mini = LLONG_MAX;
    for(int i=0;i<n;i=i+k){
        long long int sum = 0;
        for(int j=0;j<k;j++){
            sum += arr[i+j];
        }
        maxi = max(sum,maxi);
        mini = min(sum,mini);
    }
    return maxi-mini;
}
long long int solve2(vector<int>& arr)
{
    int n = arr.size();
    long long int ans = 0;
    for (int i=1;i<=sqrt(n);i++) {
        if (n%i == 0) {
            if ((n/i)!=i){
                ans = max(ans,solve(arr,n/i));
            }
            ans = max(ans,solve(arr,i));
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
        // sort(arr.begin(),arr.end());
        cout<<solve2(arr)<<endl;
    }
    return 0;
}