#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<vector<string>> b(m,vector<string>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>b[i][j];
            }
        }
        

    }
    return 0;
}