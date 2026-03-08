#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
//here sets wont work because of this example,
// no sorting will work with sets 
//n = 6;
// [1,2]
// [5,6]
// [4,5]
// [3,6]
// [2,3]
// [1,4]

//think differently
//take not take 
//but we have to store in a set so that will increase time and space complexity


//think of it as a graph problem 
// now our graph can have many cycles
//basically our problem gets reduced to colouring of graph or bipartitesness of graph
// check if any cycle is forming and if yes then is it of even or odd length
// if there is an odd length cycle -  ans is no
// else ans is yes!!

ll dfs(ll src,vector<vector<ll>>& adj,vector<ll>& vis){
    vis[src] = 1;
    ll val = 1;
    for(auto i: adj[src]){
        if(!vis[i]){
            val+=dfs(i,adj,vis);
        }
    }
    return val;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        // vector<pair<ll,ll>> v(n);
        vector<vector<ll>> adj(n+1);
        bool flag = true;
        for(int i=0;i<n;i++){
            ll val1,val2;
            cin>>val1>>val2;
            adj[val1].push_back(val2);
            adj[val2].push_back(val1);
            if(val1==val2 || adj[val1].size()>2 || adj[val2].size()>2){
                flag = false;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        vector<ll> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ll len = dfs(i,adj,vis);
                if(len&1){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
        

        
        

        

        
    }
    return 0;
}