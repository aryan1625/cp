#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll solve(vector<ll> &a,vector<ll> &b){
    int n = a.size();
    ll ans = 0;
    set<ll> st1;
    set<ll> st2;
    bool flag = true;
    for(int i=n-1;i>=0;i--){
        if(flag){
            if((a[i]==b[i])||(st2.find(a[i])!=st2.end()) || (st1.find(b[i])!=st1.end())){
                ans = i+1;
                // cout<<"i "<<i<<endl;
                break;
            }
            st1.insert(a[i]);
            st2.insert(b[i]);
        }else{
            if((a[i]==b[i])||(st2.find(b[i])!=st2.end()) || (st1.find(a[i])!=st1.end())){
                ans = i+1;
                // cout<<"i "<<i<<endl;
                break;
            }
            st1.insert(b[i]);
            st2.insert(a[i]);
        }
        flag = !flag;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        ll maxMatch=solve(a,b);

        for (int i=n-3;i<n-1;i++) {
            vector<ll> a1,b1;
            for (int j=0;j<n;j++) {
                if(j==i)continue;
                a1.push_back(a[j]);
                b1.push_back(b[j]);
            }
            maxMatch = max(maxMatch, solve(a1, b1));
        }

        cout<<maxMatch<<endl;
        // vector<ll> a1(n-1);
        // vector<ll> b1(n-1);
        // for(int i=0;i<n-1;i++){
        //     a1[i] = a[i];
        //     b1[i] = b[i];
        // }
        // a1[n-2] = a[n-1];
        // b1[n-2] = b[n-1];
        // // ll ans = max(solve(a,b),solve(a1,b1));
        // cout<<ans<<endl;
    }
    return 0;
}