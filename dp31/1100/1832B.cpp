#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        long long int sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr.begin(),arr.end());
        int i=0,j=n-1;
        //we have to find the minimum sum of k elements in an array which contains first k biggest elements and k elements with sum of minimum 
        vector<long long int> vec;
        long long int val = 0;
        for(int i=0;i<k;i++){
            vec.push_back(arr[i*2]+arr[i*2+1]);
            val += vec[i];
        }
        for(int i=k-1;i>=0;i--){
            vec.push_back(arr[n-1-i]);
        }
        //now in this vector we have to find the minimum sum of k elements;
        //22 15 13 37 25 21 k = 3
        //here we can only have these possibilities = > 22,15,13 ; 22,25,21; 25,21,22 ; 37,25,21 -sliding window?
        //sliding window
        long long int mini= val;
        for(int i=0;i<k;i++){
            val-=vec[k-1-i];
            val+=vec[2*k-1-i];
            mini = min(val,mini);
        }
        cout<<sum-mini<<endl;
    }
    return 0;
}