#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int q;
        cin>>q;
        vector<pair<int,int>> vec(q);
        for(int i=0;i<q;i++){
            cin>>vec[i].first>>vec[i].second;
            
        }
        vector<int> diff;
        for(int i=0;i<n-1;i++){
            if(arr[i]!=arr[i+1]){
                diff.push_back(i);
            }
        }
        // cout<<"diff size is: "<<diff.size()<<endl;
        for(int i=0;i<q;i++){
            auto it1 = lower_bound(diff.begin(),diff.end(),vec[i].first-1);
            auto it2 = lower_bound(diff.begin(),diff.end(),vec[i].second-1);
            if(it1==it2){
                cout<<-1<<" "<<-1<<endl;
            }else{
                int val = *(it1);
                cout<<val+1<<" "<<val+2<<endl;
            }
        }

    }
    return 0;
}