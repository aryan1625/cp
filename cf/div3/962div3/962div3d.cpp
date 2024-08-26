#include<bits/stdc++.h>
using namespace std;

int main(){
    // int t;
    // cin>>t;
    // while(t--){
    //     int n,x;
    //     cin>>n>>x;
    //     long long int ans = 0;
    //     for(long long int i=1;i<=x-2;i++){
    //         long long int st = 1,end = x-i-1;
    //         while(st<=end){
    //             long long int mid = st+(end-st)/2;
    //             long long int st2 = 1,end2 = x-i-mid;
    //             while(st2<=end2){
    //                 long long int mid2 = st2 + (end2-st2)/2;
    //                 if(mid*mid2 + mid*i + i*mid2<=n){

    //                 }
    //             }
    //         }
    //     }

    //     cout<<ans<<endl;    
    // }
    int t; cin >> t; 
    while (t--) 
    { 
        int n, x; 
        cin >> n >> x; 
        int ans = 0; 
        for (int a = 1; a <= x; a++) { 
            ans += n/a;
        } 
        cout <<ans<< endl; 
    } 
    return 0;
}