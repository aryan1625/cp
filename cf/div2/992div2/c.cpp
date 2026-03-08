#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        if(n<=40){
            if(k>(1LL<<(n-1))){
                cout<<-1<<endl;
                continue;
            }
        }   
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }
        vector<int> ans(n,0);
        ans = arr;
        int prev = 1+ceil(log2(k));
        vector<int> vis(prev,0);
        int cnt = 1;
        while(k>0){
            int val = 1+ceil(log2(k));
            int idx = prev-val;
            vis[idx] = 1;
            ans[n-cnt] = arr[n-val];
            cnt++;
            k -= (1LL << (val - 2));
        }  
        for(int i=prev-1;i>=0;i--){
            if(vis[i]==0){
                vis[i] = 1;
                ans[n-cnt] = arr[n-prev+i];
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }  
        cout<<endl;
    }
    return 0;
}