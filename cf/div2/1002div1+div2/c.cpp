#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        vector<long long int> val(n,0); 
        for(int j=n-1;j>=0;j--){
            for(int i=0;i<n;i++){
                val[i]+=arr[i][j];
            }
            long long mini = LLONG_MAX;
            int minI = -1;
            for(int i=0;i<n;i++){
                if(val[i]<mini){
                    mini = val[i];
                    minI = i;
                }
            }
            
        }
        sort(val.begin(),val.end());
        int ans = val.size()+1;
        for(int i=0;i<val.size();i++){
            if(i+1!=val[i]){
                ans = i+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}