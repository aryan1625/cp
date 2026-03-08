#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
void printFactors(int n){
    set<int> st;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            st.insert(n/i);
        }
    }
    for(auto i: st){
        cout<<i<<" ";
    }
    cout<<endl;
}
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        vector<int> mask(31,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<31;j++){
                if(((a[i]>>j)&1)==1){
                    mask[j]++;
                }
            }
        }
        for(int i=0;i<31;i++){
            st.insert(mask[i]);
        }
        vector<int> ans;
        if(st.size()==1){
            int val = *st.begin();
            if(val==0){
                for(int i=1;i<=n;i++){
                    cout<<i<<" ";
                }
                cout<<endl;
            }else{
                printFactors(val);
            }
        }else{
            if(st.find(0)!=st.end())st.erase(0);
            if(st.size()==1){
                int val = *st.begin();
                printFactors(val);
            }else{
                auto it = st.begin();
                int val1 = *it;
                st.erase(val1);
                it++;
                int val2 = *(it);
                st.erase(val2);
                int val3 = gcd(val1,val2);
                for(auto i: st){
                    val3 = gcd(val3,i);
                }
                printFactors(val3);
            }
        }

        
    }
    return 0;
}