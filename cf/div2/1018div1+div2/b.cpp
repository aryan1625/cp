#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> left(n);
        vector<int> right(n);
        vector<int> vis(n,0);
        // vector<int> vec(2*n);
        for(int i=0;i<n;i++){
            cin>>left[i];
        }
        for(int i=0;i<n;i++){
            cin>>right[i];
        }
        long long int ans = 1;
        for(int i=0;i<n;i++){
            if(left[i]>right[i]){
                ans+=left[i];
                vis[i] = 1;
            }else{
                ans+=right[i];
                vis[i] = -1;
            }
        }
        vector<int> rem(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                rem[i] = right[i];
            }else{
                rem[i]  = left[i];
            }
        }
        sort(rem.rbegin(),rem.rend());
        for(int i=0;i<k-1;i++){
            ans+=rem[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}