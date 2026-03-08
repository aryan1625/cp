#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;

int main(){
    vector<ll> v = {4,8,15,16,23,42};
    vector<vector<ll>> v2;
    do{
        v2.push_back(v);
    }while(next_permutation(v.begin(),v.end()));
    vector<ll> arr1(4);
    cout<<"? "<<1<<" "<<2<<endl;
    cin>>arr1[0];
    cout<<"? "<<2<<" "<<3<<endl;
    cin>>arr1[1];
    cout<<"? "<<3<<" "<<4<<endl;
    cin>>arr1[2];
    cout<<"? "<<4<<" "<<5<<endl;
    cin>>arr1[3];
    vector<ll> ans;
    for(int i=0;i<v2.size();i++){
        bool flag = true;
        for(int j=0;j<4;j++){
            ll ele = v2[i][j]*v2[i][j+1];
            if(ele!=arr1[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = v2[i];
            break;
        }
    }
    cout<<"! ";
    for(int i=0;i<6;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}