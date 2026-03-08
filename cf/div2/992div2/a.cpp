#include<bits/stdc++.h>
using namespace std;
pair<string,int> solve(int n,int k,vector<int>& arr){
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<n;j++){
            if(i!=j){
                int val = abs(arr[i]-arr[j]);
                if((val%k)==0){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            return {"Yes",i+1};
        }
    }
    return {"No",-1};
}
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
        pair<string,int> ans = solve(n,k,arr);
        if(ans.first=="Yes"){
            cout<<"Yes"<<endl;
            cout<<ans.second<<endl;
        }        
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}