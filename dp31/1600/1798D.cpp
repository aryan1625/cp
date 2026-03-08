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
        vector<ll> v(n);
        ll maxi = INT_MIN;
        ll mini = INT_MAX;
        vector<ll> pos;
        vector<ll> neg;
        for(int i=0;i<n;i++){
            cin>>v[i];
            maxi = max(maxi,v[i]);
            mini = min(mini,v[i]);
            if(v[i]<=0)neg.push_back(v[i]);
            else {pos.push_back(v[i]);}
        }
        sort(pos.begin(),pos.end());
        sort(neg.rbegin(),neg.rend());
        ll val = maxi - mini;
        int n1 = pos.size();
        int n2 = neg.size();
        vector<ll> ans;
        ll ele = 0;
        ll i = 0,j = 0;
        while(i<n1 && j<n2){
            if(ele+pos[i]>=val){
                ans.push_back(neg[j]);
                if(ele+neg[j]<0)ele = 0;
                else{
                    ele += neg[j];
                }
                j++;
            }else{
                ans.push_back(pos[i]);
                ele += pos[i];
                i++;
            }
        }
        while(i<n1){
            ans.push_back(pos[i]);
            ele += pos[i];
            i++;
        }
        while(j<n2){
            ans.push_back(neg[j]);
            if(ele+neg[j]<0)ele = 0;
            else{
                ele += neg[j];
            }
            j++;
        }
        if(ele>=val || abs(ele)>=val){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }


        
    }
    return 0;
}