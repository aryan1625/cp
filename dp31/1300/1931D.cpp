#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll ans = 0;
        vector<ll> arrX = arr;
        vector<ll> arrY = arr;
        for(int i=0;i<n;i++){
            arrX[i]%=x;
            arrY[i]%=y;
        }
        map<pair<ll,ll>,ll> um;
        um[{arrX[0],arrY[0]}]++;
        for(int i=1;i<n;i++){
            ll val1 = (x-arrX[i])%x;
            pair<ll,ll> p = {val1,arrY[i]};
            if(um.find(p)!=um.end()){
                ans+=um[p];
            }
            um[{arrX[i],arrY[i]}]++;
        }
        cout<<ans<<endl;

    }
    return 0;
}