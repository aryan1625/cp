#include<bits/stdc++.h>
#include <numeric>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
ll gcd(ll a, ll b)
{
    return a==0?b:gcd(b%a,a);
}
ll lcm(ll a, ll b){
    ll val = (a*b)/gcd(a,b);
    return val;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> p(n);
        vector<ll> s(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        vector<ll> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = lcm(p[i],s[i]);
        }
        // for(int i=0;i<n;i++){
        //     cout<<vec[i]<<" ";
        // }
        
        if(vec[0]!=p[0] || vec[n-1]!=s[n-1]){
            // cout<<"hello"<<endl;
            cout<<"No"<<endl;
            continue;
        }
        ll val1 = vec[0];
        ll val2 = vec[n-1];
        bool flag = true;
        for(int i=1;i<n;i++){
            val1 = gcd(val1,vec[i]);
            if(val1!=p[i]){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        for(int i=n-2;i>=0;i--){
            val2 = gcd(val2,vec[i]);
            if(val2!=s[i]){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
        
        
    }
    return 0;
}