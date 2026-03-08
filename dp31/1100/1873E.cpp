#include<bits/stdc++.h>
using namespace std;
long long int solve(vector<int>& vec,int mid){
    long long int ans = 0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]<=mid){
            ans += mid-vec[i];
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        int st = 1;
        int end = INT_MAX;
        while(st<=end){
            int mid= st + (end-st)/2;
            if(solve(vec,mid)>x){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        cout<<end<<endl;
    }
    return 0;
}