#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    // vector<long long int> pref(n,0);
    // unordered_map<int,long long int> um;
    long long int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        // int val = 0;
        // if(i!=0){
        //     val = pref[i-1];
        // }
        // pref[i] = pref[i]^arr[i]^val;
        // um[i] = pref[i];
    }
    long long int ans = 0;
    long long int m = 1;
    for(int i=0;i<32;i++){
        int a1 =  0;
        bool flag = 0;
        for(int j=0;j<n;j++){
            if((arr[j] & (1<<i))>0){
                flag = !flag;
            }
            if(flag)a1++;
        }
        for(int j=0;j<n;j++){
            ans += (m*a1);
            if((arr[j] & (1<<i))>0){
                a1 = (n-j-a1);
            }
        }
        m*=2;
    }
    cout<<ans-sum<<endl;
    return 0;
}
