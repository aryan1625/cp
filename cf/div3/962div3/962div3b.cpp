#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            // for(int j=0;j<n;j++){
            //     cin>>arr[i][j];
            // }
            cin>>arr[i];
        }
        int val = n/k;
        vector<vector<int>> ans(val,vector<int> (val,0));
        for(int i=0;i<val;i++){
            for(int j=0;j<val;j++){
                ans[i][j] = arr[i*k][j*k]-'0';
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}