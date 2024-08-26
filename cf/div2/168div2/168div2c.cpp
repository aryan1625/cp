#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = 0;
        // int n = s.size();
        vector<int> val1;
        vector<int> val2;
        val1.push_back(0);
        for(int i=1;i<n;i=i+2){
            // vis[i] = 1;
            if(s[i]=='('){
                // s[i+1] = ')';
                ans++;
                // vis[i+1] = 1;
            }
            else{
                val2.push_back(i);
                val1.push_back(i+1);
            }
        }
        int m = val2.size();
        for(int i=0;i<m;i++){
            ans += val2[i]-val1[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}