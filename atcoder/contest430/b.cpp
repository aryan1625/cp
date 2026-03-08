#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    
        ll n,m;
        cin>>n>>m;
        vector<string> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        set<vector<string>> s;
        for(int i=0;i<=n-m;i++){
            for(int j=0;j<=n-m;j++){
                vector<string> temp(m,string(m,' '));
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        temp[k][l] = v[i+k][j+l];
                    }
                }
                // for(int i=0;i<m;i++){
                //     for(int j=0;j<m;j++){
                //         cout<<temp[i][j]<<" ";
                //     }
                //     cout<<endl; 
                // }
                // cout<<endl;
                s.insert(temp);
            }
        }
        cout<<s.size()<<endl;
        
    return 0;
}