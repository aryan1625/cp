#include<bits/stdc++.h>
#include<numeric>
using namespace std;
// bool checkPalindrome(vector<int> &arr){
//     int i = 0;
//     int j = arr.size()-1;
//     while(i<=j){
//         if(arr[i++]!=arr[j--])return false;
//     }
//     return true;
// }
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
        //first check if we have a palindrome if yes then return 0;
        // if(checkPalindrome(arr)){
        //     cout<<0<<endl;
        //     continue;
        // }
        int val = abs(arr[n-1]-arr[0]);
        for(int i=1;i<n/2;i++){
            val = __gcd(val,abs(arr[n-i-1]-arr[i]));
        }
        cout<<val<<endl;

    }
    return 0;
}