#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> freq(26,0);
        bool flag = false;
        for(int i=0;i<n-1;i++){
            if(freq[s[i]-'a']>=1){
                flag = true;
                break;
            }
            freq[s[i]-'a']++;
        }
        vector<int> freq2(26,0);
        for(int i=n-1;i>0;i--){
            if(freq2[s[i]-'a']>=1){
                flag = true;
                break;
            }
            freq2[s[i]-'a']++;
        }
        
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}