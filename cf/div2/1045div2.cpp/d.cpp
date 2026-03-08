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
        bool flag = false;
        vector<vector<ll>> adj(n);
        for(int i=0;i<n-1;i++){
            ll val1,val2;
            cin>>val1>>val2;
            adj[val1-1].push_back(val2-1);
            adj[val2-1].push_back(val1-1);
        }
        ll maxi = 0;
        ll maxiI = 0;
        for(int i=0;i<n;i++){
            if(maxi<adj[i].size()){
                maxi = adj[i].size();
                maxiI = i;
            }
            if(adj[i].size()>2){
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        ll ele1,ele2,ele3;
        vector<pair<ll,ll>> v;
        for(auto it:adj[maxiI]){
            v.push_back({adj[it].size(),it});
        }
        sort(v.begin(),v.end());
        ele2 = maxiI+1;
        ele3 = v[0].second+1;
        ele1 = v[1].second+1;
        cout<<ele1<<" "<<ele2<<" "<<ele3<<endl;

        
    }
    return 0;
}