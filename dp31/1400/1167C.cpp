#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
class DisjointSet{
    private:
        vector<int> parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findUPar(int node){
            if(parent[node]==node)return node;
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionBySize(int node1,int node2){
            int ulp_1 = findUPar(node1);
            int ulp_2 = findUPar(node2);
            if(ulp_1==ulp_2)return ;
            if(size[ulp_1]<size[ulp_2]){
                parent[ulp_1] = ulp_2;
                size[ulp_2]+=size[ulp_1];
            }
            else {
                parent[ulp_2] = ulp_1;
                size[ulp_1]+=size[ulp_2];
            }
        }
        vector<ll> solve(){
            unordered_map<ll,ll>um;
            for(int i=1;i<parent.size();i++){
                ll par = findUPar(i);
                um[par]++;
            }
            vector<ll> ans(parent.size()-1,0);
            for(int i=1;i<parent.size();i++){
                ans[i-1] = um[findUPar(i)];
            }
            return ans;
        }
};
int main(){
    
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(m);
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        ll val;
        cin>>val;
        for(int j=0;j<val;j++){
            ll ele;
            cin>>ele;
            v[i].push_back(ele);
        }
    }
    for(int i=0;i<m;i++){
        for(int j = 1;j<v[i].size();j++){
            ds.unionBySize(v[i][j],v[i][j-1]);
        }
    }
    vector<ll> ans = ds.solve();
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


        
    return 0;
}