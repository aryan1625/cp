#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++){
                if(s[j]=='#'){
                    ans.push_back(j+1);
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}