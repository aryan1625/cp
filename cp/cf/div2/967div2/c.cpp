#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
        vector<int> parent,size;
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
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // vector<int> ans;
        // vector<int> vis(n+1,0);
        // vis[0] = 1;
        int cnt = 0;
        bool flag = true;
        DisjointSet ds(n);
        set<pair<int,int>> st;
        for(int i=1;i<n && flag;i++){
            for(int j=i+1;j<=n;j++){
                if(st.find({i,j})!=st.end())continue;
                if(cnt>=15*n){
                    flag = false;
                    break;
                }
                cnt++;
                cout<<"? "<<i<<" "<<j<<endl;
                int q;
                cin>>q;
                if(q==i){
                    st.insert({i,j});
                    ds.unionBySize(i,j);
                }else{
                    if(ds.findUPar(i)!=ds.findUPar(q)){
                        st.insert({min(i, q), max(i, q)});
                        ds.unionBySize(i,q);
                    }
                    if(ds.findUPar(j)!=ds.findUPar(q)){
                        st.insert({min(j, q), max(j, q)});
                        ds.unionBySize(j,q);
                    }
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<ds.parent[i]<<" ";
        // }
        // cout<<endl;
        cout<<"! ";
        for(auto i=st.begin();i!=st.end();i++){
            cout<<(*i).first<<" "<<(*i).second<<" ";
        }
        cout<<endl;
    }
    return 0;
}