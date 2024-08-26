#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<long long int> pre(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            pre[i+1] = pre[i]+arr[i];
        }
        string s;
        cin>>s;
        // pre[0] = arr[0];
        // for(int i=1;i<n;i++){
        //     pre[i] = arr[i]+pre[i-1];
        // }
        int i = 0;
        int j = n-1;
        long long int ans = 0;
        while(i<=j){
            if(s[i]=='L' && s[j]=='R'){
                ans += pre[j+1]-pre[i];
                i++;
                j--;
            }
            else if(s[i]=='R'){
                i++;
            }
            else if(s[j]=='L'){
                j--;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}