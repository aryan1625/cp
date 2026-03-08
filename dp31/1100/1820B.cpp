#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        //find maximum ones
        int n = s.size();
        int maxi = 0;
        int len = 0;
        int i = 0;
        bool flag = 0;
        while(i<n){
            if(s[i]=='1'){
                len++;
            }
            else{
                maxi =max(len,maxi);
                flag = true;
                len = 0;
            }
            i++;
        }
        maxi = max(len,maxi);
        int len2 = 0;
        i = 0;
        while(i<n){
            if(s[i]=='1')len2++;
            else{
                break;
            }
            i++;
        }
        if(flag){
            maxi = max(maxi,len+len2);
        }else{
            cout<<(long long int)maxi*maxi<<endl;
            continue;
        }
        // cout<<maxi<<endl;
        int cnt = 1;
        long long int ans = 0;
        long long int val = 0;
        while(maxi>0){
            val = (long long int)maxi*cnt;
            ans = max(val,ans);
            cnt++;
            maxi--;
        }
        cout<<ans<<endl;
    }
    return 0;
}