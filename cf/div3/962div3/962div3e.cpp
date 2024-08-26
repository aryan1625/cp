#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        // int ans = 0;
        // int a0 = 0;
        // int a1 = 0;
        int mod = 1e9+7;
        int left = 0;
        int n = s.size();
        vector<int> val(n,0);
        vector<int> val2(n,0);
        if(s[0]=='0')val[0] = 1;
        else{
            val2[0] = 1;
        }
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                val[i] = 1+val[i-1];
                val2[i] = val2[i-1];
            }
            else{
                val2[i] = 1+val2[i-1];
                val[i] = val[i-1];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            if(val[i]==val2[i])cnt++;
            for(int j=0;j<i;j++){
                if(val[i]-val[j]==val2[i]-val2[j])cnt++;
            }
            ans += cnt*(n-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}