#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
        vector<int> parent,rank,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1);
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
        void unionByRank(int node1,int node2){
            int ulp_1 = findUPar(node1);
            int ulp_2 = findUPar(node2);
            if(ulp_1==ulp_2)return ;
            if(rank[ulp_1]<rank[ulp_2]){
                parent[ulp_1] = ulp_2;
            }
            else if(rank[ulp_2]<rank[ulp_1]){
                parent[ulp_2] = ulp_1;
            }
            else{
                parent[ulp_2] = ulp_1;
                rank[ulp_1]++;
            }
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
    
    return 0;
}