#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll ans = 1;
        set<ll> st;
        st.insert(arr[0]);
        int i = 1;
        set<ll> st2;
        while(i<n){
            st2.insert(arr[i]);
            st.erase(arr[i]);
            if(st.empty()){
                ans++;
                st = st2;
                st2.clear();
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}