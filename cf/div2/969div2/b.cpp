#include<bits/stdc++.h>
using namespace std;
// void solve(vector<int>& arr,multiset<long long int> &ms,char c,int l,int r){
//     int n = arr.size();
//     for(int i=0;i<n;i++){
//         if(l<= arr[i] && arr[i]<=r){
//             ms.erase(ms.find(arr[i]));
//             arr[i] += (c == '+')?1:-1;
//             ms.insert(arr[i]);
//         }
//     }
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<long long int> arr(n);
        // multiset<long long int> ms;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            // ms.insert(arr[i]);
        }
        sort(arr.begin(),arr.end());
        vector<long long int> ans;
        for(int i=0;i<m;i++){
            int l,r;
            char c;
            cin>>c>>l>>r;
            // solve(arr,ms,c,l,r);
            if(arr[n-1]<=r && arr[n-1]>=l){
                if(c=='+')arr[n-1]++;
                else{
                    arr[n-1]--;
                }
            }
            ans.push_back(arr[n-1]);
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}