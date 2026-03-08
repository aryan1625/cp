#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int val = 1;
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            auto it = upper_bound(a.begin(),a.end(),b[i]);
            val = ((val % mod) * (((a.end() - it - cnt) % mod + mod) % mod)) % mod;
            cnt++;
        }
        cout<<val%mod<<endl;

    }
    return 0;
}