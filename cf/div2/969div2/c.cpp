#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        long long int val = gcd(a,b);
        vector<long long int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i] %= val;
        }
        long long int mini = *min_element(arr.begin(), arr.end());
        long long int maxi = *max_element(arr.begin(), arr.end());
        long long int range = maxi-mini;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            range = min(range,arr[i-1]-arr[i]+val);
        }
        cout<<range<<endl;
    }
    return 0;
}