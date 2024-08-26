#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        string ans = "";
        ans += s[0];
        int i = 0;
        for(i=1;i<n;i++){
            if(s[i]==s[i-1]){
                for(int j=0;j<26;j++){
                    char ch = 'a'+j;
                    if(ch!=s[i]){
                        ans+=ch;
                        break;
                    }
                }
                break;
            }
            ans += s[i];
        }
        if(i==n){
            for(int j=0;j<26;j++){
                char ch = 'a'+j;
                if(ch!=s[i-1]){
                    ans+=ch;
                    cout<<ans<<endl;
                    break;
                }
            }
        }
        else{
            for(int j=i;j<n;j++){
                ans += s[j];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}