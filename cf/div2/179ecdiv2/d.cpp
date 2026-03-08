#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(m);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }   
        vector<vector<int>> ans(n,vector<int>(6,0));
        sort(arr.begin(), arr.end());   
        if(m>=2*n){
            bool flag = true;
            for(int i=0;i<6;i++){
                int cnt = 0;
                for(int j=0;j<n;j++){
                    if(flag){
                        ans[j][i] = arr[cnt];
                    }else{
                        ans[j][i] = arr[m-1-cnt];
                    }
                    cnt++;
                }
                flag = !flag;
            }
        }
        else{
            for(int i=0;i<6;i++){
                int cnt = 0;
                for(int j=0;j<n;j++){
                    if(j<2){
                        if(j==0){
                            ans[j][i] = arr[cnt];
                        }
                    }else{
                        ans[j][i] = ans[j-2][i];
                        ans
                    }
                }
            }
        }
    }
    return 0;
}