#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &mat){

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> mat(n,vector<int>(n,0));
        map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
                if(mat[i][j]<0)m[i-j] = min(m[i-j],mat[i][j]);
            }
        }
        long long int ans = 0;
        for(auto i:m){
            ans += abs(i.second);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}