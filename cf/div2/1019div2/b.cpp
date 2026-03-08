#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll ans = 0;
        ll swaps = 0;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(flag){
                    ans+=2;
                    flag = false;
                    swaps++;
                }else{
                    ans++;
                }
            }else{
                if(!flag){
                    ans+=2;
                    flag = true;
                    swaps++;
                }else{
                    ans++;
                }
            }
        }
        if(swaps>2){
            cout<<ans-2<<endl;
        }else if(swaps==2){
            cout<<ans-1<<endl;
        }else{
            cout<<ans<<endl;
        }

    }
    return 0;
}