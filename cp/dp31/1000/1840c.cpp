#include<bits/stdc++.h>
using namespace std;
// long long int fact(int n)
// {
//     if(n==0)return 1;
//     long res = 1;
//     for (int i = 2; i <= n; i++)
//         res = res * i;
//     return res;
// }
// long long int nCr(int n, int r)
// {
//     return fact(n) / (fact(r) * fact(n - r));
// }
long long int solve(long long int L,long long int k){
    if (L < k) return 0;
    int x = L - k + 1;
    return (long long)x * (x + 1) / 2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k,q;
        cin>>n>>k>>q;
        vector<long long int> arr(n);
        long long int maxi = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int left = 0;
        long long int ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>q){
                ans += solve(i-left,k);
                left = i+1;
            }
        }
        ans += solve(n-left,k);
        cout<<ans<<endl;
    }
    return 0;
}