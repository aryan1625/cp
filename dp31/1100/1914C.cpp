#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        long long int ans = 0;
        long long int sum = 0;
        long long int maxi = 0;
        int i = 0;
        while(k>0 && i<n){
            sum += a[i];
            maxi = max(maxi,(long long int)b[i]);
            ans = max(ans,sum+maxi*(k-1));
            i++;
            k--;
        }
        cout<<ans<<endl;
    }
    return 0;
}