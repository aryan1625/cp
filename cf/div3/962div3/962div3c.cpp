#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string a,b;
        cin>>a;
        cin>>b;
        vector<pair<int,int>> arr(q,{0,0});
        for(int i=0;i<q;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        vector<int> ans(q,0);
        vector<vector<int>> freq1(n+1,vector<int>(26,0));
        // vector<vector<int>> freq2(n+1,vector<int>(26,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                freq1[i][j] = freq1[i-1][j];
                // freq2[i+1][j]        = freq2[i][j];
            }
            freq1[i][a[i-1]-'a']++;
            freq1[i][b[i-1]-'a']--;
        }
       for(int i=0;i<q;i++){
        // vector<int> freq(26,0);
        int left = arr[i].first-1;
        int right = arr[i].second;
        vector<int> freq2(26,0);
        for(int k=0;k<26;k++){
            freq2[k] = freq1[right][k]-freq1[left][k];
        }
        int cnt = 0;
        for(int k=0;k<26;k++){
            cnt += abs(freq2[k]);
        }
        ans[i] = cnt/2;
       }
       for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
       }
    }
    return 0;
}