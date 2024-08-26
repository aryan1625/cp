#include<bits/stdc++.h>
using namespace std;
// class DisjointSet{
//     private:
//         vector<int> parent,size;
//         int sz = 1;
//     public:
//         DisjointSet(int n){
//             parent.resize(n+1);
//             size.resize(n+1);
//             for(int i=0;i<=n;i++){
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
//         int findUPar(int node){
//             if(parent[node]==node)return node;
//             return parent[node] = findUPar(parent[node]);
//         }
//         void unionBySize(int node1,int node2){
//             int ulp_1 = findUPar(node1);
//             int ulp_2 = findUPar(node2);
//             if(ulp_1==ulp_2)return ;
//             sz++;
//             if(size[ulp_1]<size[ulp_2]){
//                 parent[ulp_1] = ulp_2;
//                 size[ulp_2]+=size[ulp_1];
//             }
//             else {
//                 parent[ulp_2] = ulp_1;
//                 size[ulp_1]+=size[ulp_2];
//             }
//         }
//         int findSize(){
//             return sz;
//         }
// };
// void joinn(vector<string>& vec,DisjointSet &ds){
//     int n = vec[0].size();
//     int arr1[4] = {1,0,-1,0};
//     int arr2[4] = {0,1,0,-1};
//      for (int i = 0; i < 2; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (vec[i][j] == '.') {
//                 int val = i * n + j;
//                 for (int k = 0; k < 4; ++k) {
//                     int ni = i + arr1[k];
//                     int nj = j + arr2[k];
//                     if (ni >= 0 && ni < 2 && nj >= 0 && nj < n && vec[ni][nj] == '.') {
//                         int val2 = ni * n + nj;
//                         ds.unionBySize(val, val2);
//                     }
//                 }
//             }
//         }
//     }
//     return ;
// }
// int solve(vector<string>& vec){
//     int n = vec[0].size();
//     vector<vector<int>> vis(2,vector<int>(n,0));
//     int ans = 0;
//     for(int i=0;i<2;i++){
//         for(int j=0;j<n;j++){
//             if(!vis[i][j] && vec[i][j]=='.'){
//                 dfs(i,j,vec,vis);
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> vec(2);
        int ans = 0;
        cin>>vec[0];
        cin>>vec[1];
        // DisjointSet ds(2*n);
        // joinn(vec,ds);
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j]=='.'){
                    DisjointSet ds2 = ds;
                    int val = i*n+j;
                    vec[i][j] = 'x';
                    if (i > 0 && vec[i - 1][j] == '.') ds.unionBySize(val, (i - 1) * n + j);
                    if (i < 1 && vec[i + 1][j] == '.') ds.unionBySize(val, (i + 1) * n + j);
                    if (j > 0 && vec[i][j - 1] == '.') ds.unionBySize(val, i * n + (j - 1));
                    if (j < n - 1 && vec[i][j + 1] == '.') ds.unionBySize(val, i * n + (j + 1));

                    if(ds2.findSize()==3)ans++;
                    vec[i][j] = '.';
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}