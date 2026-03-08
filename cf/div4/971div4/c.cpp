#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        long long int val1 = ceil(double(x)/k);
        long long int val2 = ceil(double(y)/k);
        long long int ans = 0;
        if(val2>=val1){
            ans += val2*2;
        }else{
            ans+= val1*2-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}