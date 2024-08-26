#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        // int ans = 0;
        int n,p;
        cin>>n>>p;
        vector<pair<int,int>> arr(n,{0,0});
        for(int i=0;i<n;i++){
            cin>>arr[i].second;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
        }
        sort(arr.begin(),arr.end());
        int tot = n-1;
        int i = 0;
        long long int ans = p;
        long long int ticket = 0;
        while(i<n && arr[i].first<p){
            ticket += arr[i].second;
            if(ticket==0)ans += p;
            if(tot>=arr[i].second){
                ans += (long long int)arr[i].first*arr[i].second;
                tot-=arr[i].second;
            }
            else{
                ans += (long long int)arr[i].first*tot;
                tot = 0;
                break;
            }
            ticket--;
            i++;
        }
        ans += (long long int)tot*p;
        cout<<ans<<endl;
    }
    return 0;
}