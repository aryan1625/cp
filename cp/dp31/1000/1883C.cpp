#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        //constraints k is from 2 to 5
        int n,k;
        cin>>n>>k;
        int mini = 1e9;
        vector<int> arr(n);
        bool flag = true;
        int even = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0)even++;
            if((arr[i]%k)==0){
                mini = 0;
                flag = false;
            }
            if(flag)mini = min(mini,(k-(arr[i]%k)));
        }
        if(k==4){
            if(even>=2)cout<<0<<endl;
            else if(even==1)cout<<min(mini,1)<<endl;
            else{
                cout<<min(mini,2)<<endl;
            }
            continue;
        }
        cout<<mini<<endl;
        // cout<<endl;
    }
    return 0;
}