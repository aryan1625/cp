#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> vis(n,0);
        vis[arr[0]-1] = 1;
        bool flag = true;
        for(int i=1;i<n;i++){
            if(((arr[i]<n && vis[arr[i]]==0 )|| arr[i]>=n) && ((arr[i]>1 && vis[arr[i]-2]==0)||arr[i]<=1) ){
                flag = false;
                break;
            }
            else{
                vis[arr[i]-1] = 1;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}