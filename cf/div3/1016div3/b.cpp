#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        // long long n;
        // cin>>n;
        // string s = to_string(n);
        string s;
        cin>>s;
        int n1 = s.size();
        int cnt = 0;
        int i = n1-1;
        for(i=n1-1;i>=0;i--){
            if(s[i]=='0'){
                cnt++;  
            }else{
                break;
            }
        }
        for(int j=0;j<i;j++){
            if(s[j]!='0')cnt++;
        }
        cout<<cnt<<endl;


    }
    return 0;
}