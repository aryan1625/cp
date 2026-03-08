#include<bits/stdc++.h>
int mod = 998244353;
using ll = long long ;
using ld = long double ;
using namespace std;
class DisjointSet{
    public:
    vector<ll> parent, rank;
    DisjointSet(ll n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    ll findUPar(ll node){
        if(node==parent[node])return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(ll u, ll v){
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    int findSize(){
        unordered_map<int,int> um;
        for(int i=0;i<parent.size();i++){
            um[findUPar(i)]++;
        }
        return um.size();
    }
};
bool dfs(ll node, vector<ll> &adj, vector<ll> &vis){
    vis[node] = 1;
    ll next = adj[node];
    if(vis[next]==0){
        // vis[next] = 1;
        if(adj[next]==node){
            vis[next] = 1;
            return true;
        }
        return dfs(next,adj,vis);
    }else{
        return false;
    }
    return true;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        vector<ll> adj(n);
        vector<ll> indeg(n,0);
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            adj[i] = v[i]-1;
            ds.unionByRank(i,v[i]-1);
            indeg[v[i]-1]++;
        }
        ll maxi = ds.findSize();
        //find nodes with cycle length = 2;
        unordered_map<ll,ll> um;    
        vector<ll> temp;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                if(um.find(ds.findUPar(i))==um.end()){
                    // maxi--;
                    um[ds.findUPar(i)] = 1;
                    temp.push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(um.find(ds.findUPar(i))==um.end()){
                um[ds.findUPar(i)] = 1;
                temp.push_back(i);
            }
        }
        //check for 2 cycles
        ll tot = 0;
        // for(int i=0;i<n;i++){
        //     if(i==adj[adj[i]])tot++;
        // }
        // tot/=2;
        ll tot2 = 0;
        vector<ll> vis(n,0);
        // cout<<"temp size is "<<temp.size()<<endl;
        for(int i=0;i<temp.size();i++){
            ll node = temp[i];
            // cout<<"node is "<<node<<endl;   
            if(dfs(node,adj,vis)){
                tot++;
            }else{
                tot2++;
            }
        }
        if(tot){
            tot2++;
        }
        cout<<tot2<<" "<<maxi<<endl;
    }
    return 0;
}