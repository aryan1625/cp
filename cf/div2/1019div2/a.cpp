#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_set<int> s;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }
        cout<<s.size()<<endl;

    }
    return 0;
}