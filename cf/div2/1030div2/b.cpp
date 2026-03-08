#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;

int main(){
    int t;
    cin>>t;
    while(t--){
       ll n;
       cin>>n;
       ll k = 2*(n-1);
       cout<<k<<endl;
       vector<pair<ll,ll>> vec(k);
       bool flag = true;
       ll cnt = 1;
       ll val = (n&1)==1?n-1:n;
       for(int i=0;i<val;i++){
        if(flag){
            vec[i].first = 1;
            vec[i].second = n-1;
        }else{
            vec[i].first = cnt;
            vec[i].second = n;
            cnt++;
        }
        flag = !flag;
       }
       ll idx = 2;
       for(int i=0;i<val;i=i+2){
        cout<<idx<<" "<<vec[i].first<<" "<<vec[i].second<<endl;
        cout<<idx<<" "<<vec[i+1].first<<" "<<vec[i+1].second<<endl;
        idx++;
       }
       for(int i=0;i<k-val;i=i+2){
        cout<<idx<<" "<<vec[k-val-i-1].first<<" "<<vec[k-val-i-1].second<<endl;
        cout<<idx<<" "<<vec[k-val-i-2].first<<" "<<vec[k-val-i-2].second<<endl;
        idx++;
       }


       
       

    }
    return 0;
}