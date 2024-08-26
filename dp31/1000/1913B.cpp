#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int cntZ = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')cntZ++;
        }
        int cntO = n-cntZ;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(cntO==0){
                    ans = n-i;
                    break;
                }
                else{
                    cntO--;
                }
            }
            else{
                if(cntZ==0){
                    ans = n-i;
                    break;
                }
                else{
                    cntZ--;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}