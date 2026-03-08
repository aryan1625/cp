#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i].first>>vec[i].second;
        }
        int x1 = vec[0].first;
        int y1 = vec[0].second;
        int x2 = x1+m;
        int y2 = y1+m;
        for(int i=1;i<n;i++){
            x2+=vec[i].first;
            y2+=vec[i].second;
        }
        cout<<2*(x2-x1+y2-y1)<<endl;

    }
    return 0;
}