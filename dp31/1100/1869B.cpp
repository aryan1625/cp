#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i].first>>vec[i].second;
        }
        int x1 = vec[a-1].first,y1 = vec[a-1].second,x2 = vec[b-1].first,y2 = vec[b-1].second;
        int ans = 0;
        long long int a1 = LLONG_MAX/2;
        long long int b1 = LLONG_MAX/2;
        long long int val = (long long int )abs(x2-x1)+abs(y2-y1);
        for(int i=0;i<k;i++){
            a1 = min(a1,(long long int)abs(x1-vec[i].first)+abs(y1-vec[i].second));
            b1 = min(b1,(long long int)abs(x2-vec[i].first)+abs(y2-vec[i].second));
        }
        cout<<min(a1+b1,val)<<endl;
    }
    return 0;
}