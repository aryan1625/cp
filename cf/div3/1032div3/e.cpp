#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
// ll solve(int idx,string &s,string &e,bool flag){
//     int n = s.size();
//     if(idx>=n)return 0;
//     ll ans= 0;
//     char a1 = s[idx];
//     char a2 = e[idx];
//     if(!flag){
//         return 0;
//     }
//     if(flag && ((a1=='9' && a2=='0') || ((a2-a1)<=1))){
//         //flag will remain true;
//         ans = 1+solve(idx+1,s,e,1);
//         return ans;
//     }

// }
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        string s = to_string(l);
        string e = to_string(r);
        int n = s.size();
        ll ans = 0;
        bool flag = true;
        for(int i=0;i<n;i++){
            char a1 = s[i];
            char a2 = e[i];
            if((a2-a1)==0){
                if(flag){
                    ans+=2;
                }else{
                    break;
                }
                
            }else if(a1=='9' && a2=='0'){
                ans++;
            }
            else if((a2-a1)==1){
                if(flag){
                    ans++;
                    flag = false;
                }else{
                    break;
                }
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}