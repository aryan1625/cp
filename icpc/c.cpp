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
        vector<long long int> val;
        sort(arr.begin(),arr.end());
        long long int ans = 0;
        // long long int ans2 = 0;
        vector<long long int> pre(n);
        vector<long long int> pre2(n);
        pre[0] = arr[0];
        for(int i=1;i<n;i++){
            pre[i] += arr[i]+pre[i-1];
        }
        for(int i=0;i<k;i++){
            pre2[i] = arr[i];
            val.push_back(pre[i]);
        }
        // pre.push_back(ans);
        for(int i=k;i<n;i++){
            pre2[i] = arr[i];
            if(i>k)pre2[i]+=pre2[i-k-1];
            val.push_back(pre[i]-pre2[i-k]);
        }
        for(int i=0;i<n;i++){
            cout<<val[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}