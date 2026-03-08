#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
        vector<int> parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
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
        vector<int> arr1(n),arr2(n);
        for(int i=0;i<n;i++){
            cin>>arr1[i];
            arr1[i]-=1;
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
            arr2[i]-=1;
        }
        DisjointSet ds(n);
        for (int i=0;i<n;i++){
            ds.unionBySize(i,arr1[i]);
        }
        vector<long long > ans(n,0);
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            int node = ds.findUPar(i);
            um[node]++;
        }
        unordered_set<int> us;
        for(int i=0;i<n;i++){
            int node = ds.findUPar(arr1[arr2[i]]);
            if(!us.count(node)){
                us.insert(node);
                ans[i] = um[node];
            }
        }   

        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}