#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string str){
    int s = 0;
    int e = str.size()-1;
    while(s<=e){
        if(str[s++]!=str[e--])return false;
    }
    return true;
}
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = 0;
    // int cnt = 0;
    sort(s.begin(),s.end());
    do{
        bool flag = true;
        for(int i=0;i<=n-k;i++){
            string str = s.substr(i,k);
            if(isPalindrome(str)){
                flag = false;
                break;
            }
        }
        if(flag)ans++;
        // cnt++;
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans<<endl;
    return 0;
}