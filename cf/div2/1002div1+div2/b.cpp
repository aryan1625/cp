#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = -1;
        int i = 1;
        for(i=1;i<n;i++){
            if(arr[i]==1){
                if(k<n)k++;
                else{
                    break;
                }
            }else{
                ans = 1;
            }
        }
        if(ans==1){
            cout<<1<<endl;
            continue;
        }else if(i>=2){
            cout<<2<<endl;
            continue;
        }
        int cnt = 2;
        for(int j=i+2;j<n;j=j+2){
            if(arr[j]!=cnt){
                ans = cnt;
                break;
            }else{
                cnt++;
            }
        }
        if(ans==-1)cout<<cnt<<endl;
        else cout<<ans<<endl;



    }
    return 0;
}



