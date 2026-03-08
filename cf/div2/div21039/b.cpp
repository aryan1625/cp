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
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        string s;
        s = "LL";
        int i = 2;
        int j = n-1;
        int prev = v[1];
        bool flag = 0;
        while(i<=j){
            int ele1= v[i];
            int ele2 = v[j];
            if(ele1>prev && ele2>prev){
                if(ele1>ele2){
                    prev = ele1;
                    s+='L';
                    i++;
                }else{
                    prev = ele2;
                    s+='R';
                    j--;
                }
                flag = 0;
            }else if(ele1<prev && ele2<prev){
                if(ele1>ele2){
                    prev = ele2;
                    s+='R';
                    j--;
                }else{
                    prev = ele1;
                    s+='L';
                    i++;
                }
                flag = 1;
            }else if(ele1>prev && ele2<prev){
                if(flag){
                    prev = ele1;
                    s+='L';
                    i++;
                }else{
                    prev = ele2;
                    s+='R';
                    j--;
                }
                flag = !flag;
            }else{
                if(!flag){
                    prev = ele1;
                    s+='L';
                    i++;
                }else{
                    prev = ele2;
                    s+='R';
                    j--;
                }
                flag = !flag;
            }
            
        }
        cout<<s<<endl;
        
    }
    return 0;
}