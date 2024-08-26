#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        //smallest+ all second smallest
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        int mini = INT_MAX;
        int mini2 = INT_MAX;
        long long int ans = 0;
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                int val;
                cin>>val;
                arr[i].push_back(val);
            }
            sort(arr[i].begin(),arr[i].end());
            mini = min(mini,arr[i][0]);
            ans += arr[i][1];
            mini2 = min(mini2,arr[i][1]);
        }
        cout<<ans+mini-mini2<<endl;
    }
    return 0;
}