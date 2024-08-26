#include<bits/stdc++.h>
using namespace std;
string solve(vector<int>& arr,int n){
    // vector<int> a;
    int a1 = 0,a0= 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        while(i<n && arr[i]==0){
            flag = true;
            i++;
        }
        if(flag)a0++;
        if(i<n && arr[i]==1){
            flag= false;
            a1++;
        }
    }
    if(a1>a0)return "yes";
    return "no";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = s[i]-'0';
        }
        cout<<solve(arr,n)<<endl;
    }
    return 0;
}