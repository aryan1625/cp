#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
       ll k,a,b,x,y;
       cin>>k>>a>>b>>x>>y;
       ll ans1 = 0;
       ll cnt= 0;
       ll cnt2 = 0;
       ll K = k;
       if(k>=a){
        k-=a;
        cnt+=k/x+1;
        k = K-x*cnt;
        if(k>=b){
            cnt+=(k-b)/y;
        }
       }
       ans1 = max(ans1,cnt);
       if(K>=b){
        K-=b;
        cnt2+=K/y+1;
        if(b>a){
            cnt2+=(b-a)/x;
        }
       }
       ans1 = max(ans1,cnt2);
       cout<<ans1<<endl;
       
       

    }
    return 0;
}