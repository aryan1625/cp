#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> v(n,vector<ll>(m));
        ll maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                maxi = max(maxi,v[i][j]);
            }
        }
        vector<ll> row(n,0);
        vector<ll> col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==maxi){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        ll maxr = 0;
        ll maxc = 0;
        ll r = 0;
        ll c = 0;
        for(int i = 0;i<n;i++){
            if(maxr<row[i]){
                r = i;
                maxr = row[i];
            }
        }       
        for(int i = 0;i<m;i++){
            if(maxc<col[i]){
                c = i;
                maxc = col[i];
            }
        }
        if(maxc>maxr){
            for(int i=0;i<n;i++){
                v[i][c]--;   
            }  
            maxi = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    maxi = max(maxi,v[i][j]);
                }
            }  
            vector<ll> row2(n,0);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(v[i][j]==maxi){
                        row2[i]++;
                    }
                }
            }
            maxr = 0;
            r = 0;
            for(int i = 0;i<n;i++){
                if(maxr<row2[i]){
                    r = i;
                    maxr = row2[i];
                }
            }   
            for(int i=0;i<m;i++){
                if(i!=c)v[r][i]--;   
            }

        }else{
            for(int i=0;i<m;i++){
                v[r][i]--;   
            }   
            maxi = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    maxi = max(maxi,v[i][j]);
                }
            }   
            vector<ll> col2(m,0);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(v[i][j]==maxi){
                        col2[j]++;
                    }
                }
            }
            maxc = 0;
            c = 0;
            for(int i = 0;i<m;i++){
                if(maxc<col2[i]){
                    c = i;
                    maxc = col2[i];
                }
            }
            for(int i=0;i<n;i++){
                if(i!=r)v[i][c]--;   
            }
        }
        // cout<<"r: "<<r<<" c: "<<c<<endl;       
        // for(int i=0;i<m;i++){
        //     v[r][i]--;   
        // }
        // for(int i=0;i<n;i++){
        //     if(i!=r)v[i][c]--;   
        // }
        ll max2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                max2 = max(max2,v[i][j]);
            }
        }
        cout<<max2<<endl;
    }
    return 0;
}