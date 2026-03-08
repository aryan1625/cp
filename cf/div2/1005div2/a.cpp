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
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                while (i < n && s[i] == '1') i++; 
                if (flag) cnt += 2;
                else cnt++;
            } else {
                while (i < n && s[i] == '0') i++; 
                flag = true;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}