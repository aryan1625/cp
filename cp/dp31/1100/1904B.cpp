#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> arr = a;
        unordered_map<int,int> um;
        sort(arr.begin(),arr.end());
        // um[arr[0]] = 0;
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            int j = i+1;
            while(j<n && sum>=arr[j]){
                sum+=arr[j];
                j++;
            }
            int k = j-1;
            for (int k = i; k<j; k++) {
                um[arr[k]] = j-1;
            }
            i = j-1;
        }
        for(int i=0;i<n;i++){
            cout<<um[a[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}