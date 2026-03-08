#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = i+1;
        }
        for(int i=n-2;i>=0;i--){
            int pos = i;
            for(int j=i+1;j<n;j++){
                if(s[ans[pos]-1][ans[j]-1]=='0'){
                    swap(ans[pos],ans[j]);
                    pos = j;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}