#include<bits/stdc++.h>
using namespace std;
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
        int ans = 0;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                flag = true;
            }else{
                if(flag){
                    ans++;
                    flag = false;
                }
            }
        }
        if(flag){
            ans++;
        }
        cout<<min(ans,2)<<endl;
    }
    return 0;
}