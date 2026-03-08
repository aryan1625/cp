#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<ll> ans(n,0);
        ans[0] = 2*v[0];
        set<ll> s;
        s.insert(0);
        s.insert(v[0]);
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1];
            auto it3 = s.lower_bound(v[i]);
            if(it3==s.end()){
                it3--;
                ll diff1 = v[i]-(*it3);
                ll diff = *it3-*prev(it3);
                if(diff>diff1){
                    ans[i]+=2*diff1-diff;
                }else{
                    ans[i]+=diff1;
                }
            }
            else{
                auto it4= next(it3);
                auto it2 = prev(it3);
                // auto it1 = prev(it2);
                if(it2==s.begin() && it4==s.end()){
                    ans[i] = min(v[i],*it3 - v[i])+(*it3);
                }else if(it2==s.begin()){
                    ans[i]+= v[i]+min(v[i],*it3-v[i])+min(*it4 - *it3, *it3 - v[i])-min(*it3,*it4-*it3)-(*it3);
                }
                else if(it4==s.end()){
                    auto it1 = prev(it2);
                    ans[i] += min(*it2-*it1,v[i]-*it2)+min(v[i]-*it2,*it3-v[i])+*it3-v[i]-min(*it2 - *it1, *it3-*it2)-(*it3-*it2);
                }
                else{
                    auto it1 = prev(it2);
                    ans[i] += min(*it2-*it1,v[i]-*it2)+min(v[i]-*it2,*it3-v[i])+min(*it4-*it3,*it3-v[i])-min(*it2 - *it1, *it3-*it2)-min(*it4-*it3,*it3-*it2);
                }
            }
            s.insert(v[i]);
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
    return 0;
}