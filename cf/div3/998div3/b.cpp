#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> c(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        for(int i=0;i<n;i++){
            sort(c[i].begin(),c[i].end());
        }
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = {c[i][0],i};
        }
        sort(vec.begin(),vec.end());
        bool flag = true;
        int val = -1;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(c[vec[i].second][j]<val){
                    flag = false;
                    break;
                }else{
                    val = c[vec[i].second][j];
                }
            }
            if(!flag)break;
        }
        if(!flag){
            cout<<-1<<endl;
        }else{
            for(int i=0;i<n;i++){
                cout<<vec[i].second+1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}