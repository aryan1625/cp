#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> vec(2);
        // vector<int> vis(3,0);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            vec[y].push_back(x);
        }    
        sort(vec[0].begin(),vec[0].end());
        sort(vec[1].begin(),vec[1].end());
        int n1 = vec[0].size();
        int n2 = vec[1].size();
        int i = 0,j = 0;
        long long int ans = 0;
        while(i<n1 && j<n2){
            if(vec[0][i]==vec[1][j]){
                i++;
                j++;
                ans += n1+n2-2;
            }else if(vec[0][i]>vec[1][j]){
                j++;
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n1;i++){
            if(binary_search(vec[1].begin(),vec[1].end(),vec[0][i]+1)&&binary_search(vec[0].begin(),vec[0].end(),vec[0][i]+2))ans++;
        }
        for(int i=0;i<n2;i++){
            if(binary_search(vec[0].begin(),vec[0].end(),vec[1][i]+1)&&binary_search(vec[1].begin(),vec[1].end(),vec[1][i]+2))ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}