#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long int c;
        cin>>n>>c;
        vector<int> arr(n);
        long long int sum =  0;
        long long int sqSum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
            sqSum += (long long int)arr[i]*arr[i];
        }
        long long int val = sum/n;
        cout<<((long long int)sqrt((val*val-(sqSum-c)/n))-val)/2<<endl;
    }
    return 0;
}