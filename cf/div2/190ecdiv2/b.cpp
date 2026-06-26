#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
using ll = long long;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n = s.size();
        ll ans = 0;
        string s2;
        for(int i=0;i<n;i++){
            if(s[i]=='4'){
                ans++;
                continue;
            }
            s2+=s[i];
        }
        int n2 = s2.size();
        vector<int> zer(n+1,0);
        int hi = n2-1;
        int low= 0;
        for(int i=n2-1;i>=0;i--){
            if(s2[i]=='2'){
                hi = i;
                break;
            }
        }
        for(int i=0;i<=n2-1;i++){
            if(s2[i]!='2'){
                low = i;
                break;
            }
        }
        ll cnt1 = 0;
        ll cnt2 = 0;
        vector<int> one;
        vector<int> two;
        one.push_back(0);
        for(int i=low;i<=hi;i++){
            if(s2[i]=='2'){
                if(cnt1!=0){
                    one.push_back(cnt1);
                    cnt1 = 0;
                }
                cnt2++;
            }else{
                if(cnt2!=0){
                    two.push_back(cnt2);
                    cnt2 = 0;
                }
                cnt1++;
            }
        }
        if(cnt1!=0){
            one.push_back(cnt1);
        }else if(cnt2!=0){
            two.push_back(cnt2);
        }
        two.push_back(0);
        for(int i=1;i<one.size();i++){
            one[i]+=one[i-1];
        }
        for(int i=two.size()-2;i>=0;i--){
            two[i]+=two[i+1];
        }
        if(two.size()!=one.size()){
            cout<<ans<<endl;
            continue;
        }
        int cnt3 = n;
        for(int i=0;i<one.size();i++){
            cnt3 = min(cnt3,one[i]+two[i]);
        }
        cout<<ans+cnt3<<endl;
     }
    return 0;
}