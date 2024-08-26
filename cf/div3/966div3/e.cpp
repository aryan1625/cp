#include<bits/stdc++.h>
using namespace std;
void fillmat(vector<vector<int>>& grid,int i,int j,int k){
    for(int a=i;a<i+k;a++){
        for(int b=j;b<j+k;b++){
            grid[a][b]++;
        }
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int w;
        cin>>w;
        vector<int> arr(w);
        for(int i=0;i<w;i++){
            cin>>arr[i];
        } 
        sort(arr.rbegin(), arr.rend());
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                fillmat(grid,i,j,k);
            }
        }
        vector<int> val;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                val.push_back(grid[i][j]);
            }
        }
        sort(val.rbegin(),val.rend());
        long long int ans = 0;
        for(int i=0;i<w;i++){
            ans += (long long int)arr[i]*val[i];
        }
        cout<<ans<<endl;      
    }
    return 0;
}