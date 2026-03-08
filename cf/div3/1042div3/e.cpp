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
        vector<ll> A(n);
        vector<ll> B(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
        }
        if(A[n-1]!=B[n-1]){
            cout<<"No"<<endl;
            continue;
        }
        vector<int> vec(2,A[n-1]);
        bool flag = true;
        for(int i=n-2;i>=0;i--){
            ll val1 = A[i]^vec[0];
            ll val2 = A[i]^vec[1];
            vec[0] = A[i];
            vec[1] = B[i];
            if(B[i]!=A[i] && B[i]!=val1 && B[i]!=val2){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}