#include<bits/stdc++.h>
using namespace std;
// pair<int,long long int> solve(int i,int n,int k){
//     long long int val = ((long long int)(2*k+i-1)*(n-2*i)+(long long int)n*(n-i))/2;
//     if(val==0)return {0,0};
//     // cout<<abs(val)<<endl;
//     return {val/abs(val),abs(val)};
// }
long long int sum(int a,int n){
    return ((long long int)n*((long long int)2*a+n-1))/2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        // long long int ans;
        int st = 1;
        int end = n;
        int mid = st + (end-st)/2;
        long long int x = sum(k,mid);
        long long int y = sum(k+mid,n-mid);
        long long int ans = abs(x-y);
        while(st<=end){
            int mid = st + (end-st)/2;
            long long int x = sum(k,mid);
            long long int y = sum(k+mid,n-mid);
            ans = min(ans,abs(x-y));
            if(x==y){
                ans = 0;
                break;
            }else if(x>y){
                end = mid-1;
            }else{
                st = mid+1;
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}