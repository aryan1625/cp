#include<bits/stdc++.h>
using namespace std;
int findlat(int number){
    for(int i=0;i<32;i++){
        if((number>>i)&1)return i;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr1(n);
        vector<int> arr2(q);
        vector<pair<int,pair<long long int,int>>> vec(n);
        for(int i=0;i<n;i++){
            cin>>arr1[i];
            vec[i]={findlat(arr1[i]),{arr1[i],i}};

        }
        for(int i=0;i<q;i++){
            cin>>arr2[i];
        }
        sort(vec.begin(),vec.end());
        vector<int> vec2(n);
        for(int i=0;i<n;i++){
            vec2[i] = vec[i].first;
            // cout<<vec2[i]<<" ";
        }
        for(int i=0;i<q;i++){
            auto it  = lower_bound(vec2.begin(),vec2.end(),arr2[i])-vec2.begin();
            // cout<<it<<endl;
            int val = pow(2,arr2[i]-1);
            for(int j=it;j<n;j++){
                vec2[j] = arr2[i]-1;
                vec[j].first = arr2[i]-1;
                vec[j].second.first += val;
            }
        }
        vector<long long int> ans(n);
        for(int i=0;i<n;i++){
            ans[vec[i].second.second] = vec[i].second.first;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}