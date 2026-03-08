#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<vector<long long int>> grid(n,vector<long long int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int len = s.size();
        int i1 = 0,j1 = 0;
        for(int i=0;i<len;i++){
            grid[i1][j1] = -1e16;
            if(s[i]=='D'){
                i1++;
            }else{
                j1++;
            }
        }
        grid[i1][j1] = -1e16;
        vector<pair<long long int,int>> ls(m+n,{0,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1e16){
                    ls[n+j].first += grid[i][j];
                    ls[i].first += grid[i][j];
                }else{
                    ls[n+j].second++;
                    ls[i].second++;
                }
            }
        }
        queue<pair<int,long long int >>q;
        for(int i=0;i<ls.size();i++){
            if(ls[i].second==1){
                q.push({i,ls[i].first});
            }
        }
        while(!q.empty()){
            pair<int,long long int> p = q.front();
            q.pop();
            if(p.first>=n){
                for(int i=0;i<n;i++){
                    if(grid[i][p.first-n]==-1e16){
                        grid[i][p.first-n] = -p.second;
                        ls[i].second--;
                        ls[i].first+=grid[i][p.first-n];
                        if(ls[i].second==1){
                            q.push({i,ls[i].first});
                        }   
                    }
                }
            }else{
                 for(int i=0;i<m;i++){
                    if(grid[p.first][i]==-1e16){
                        grid[p.first][i] = -p.second;
                        ls[i+n].second--;
                        ls[i+n].first+=grid[p.first][i];
                        if(ls[i+n].second==1){
                            q.push({i+n,ls[i+n].first});
                        }   
                    }
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}