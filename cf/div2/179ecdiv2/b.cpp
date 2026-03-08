#include<bits/stdc++.h>
using namespace std;
vector<int> fib(int n){
    int a = 0, b=1;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int c = a + b;
        ans.push_back(c);
        a = b;
        b = c;
    }
    return ans;   
}
// bool solve(int i,int h,int w,int l,vector<int> &fibs){
//     if(i<0)return true;
//     bool ans = false;
//     bool val1 = false, val2 = false, val3 = false;
//     if(fibs[i]<=(w-fibs[i+1]) && fibs[i]<=l && fibs[i]<=h){
//         val1 = solve(i-1,h,w-fibs[i+1],l,fibs);
//     }
//     if(fibs[i]<=w && fibs[i]<=(l-fibs[i+1]) && fibs[i]<=h){
//         val2 = solve(i-1,h,w,l-fibs[i+1],fibs);
//     }
//     if(fibs[i]<=w && fibs[i]<=(h-fibs[i+1]) && fibs[i]<=l){
//         val3 = solve(i-1,h-fibs[i+1],w,l,fibs);
//     }
//     return val1 || val2 || val3;
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> w(m);
        vector<int> l(m);
        vector<int> h(m);
        for(int i = 0; i < m; i++){
            cin>>w[i]>>l[i]>>h[i];
        }
        vector<int> fibs = fib(n);
        long long int maxi = 0;
        // for(int i = 0; i < n; i++){
        //     maxi += fibs[i]*fibs[i]*fibs[i];
        // }
        string ans = "";
        for(int i = 0; i < m; i++){
            //first compare volume
            long long int vol = w[i] * l[i] * h[i];
            // if(vol > maxi){
            //     ans+='0';
            //     continue;
            // }
            bool flag = true;
            vector<int> vec = {w[i],l[i],h[i]};
            for(int j=n-1;j>=0;j--){
                if(fibs[j]>vec[0] || fibs[j]>vec[1] || fibs[j]>vec[2]){
                    flag = false;
                    break;
                }
                sort(vec.begin(),vec.end());
                vec[2]-= fibs[j];
            }
            if(flag){
                ans+='1';
            }
            else {
                ans+='0';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}