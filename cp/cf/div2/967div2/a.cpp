#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            um[arr[i]]++;
        }
        int maxi = 0;
        for(auto i: um){
            maxi = max(maxi,i.second);
        }
        cout<<n-maxi<<endl;

    }
    return 0;
}