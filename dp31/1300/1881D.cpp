#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void getPrimeFactors(ll num,unordered_map<ll,ll> &um){
    if(num<=1)return;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            while(num%i==0){
                um[i]++;
                num/=i;
            }
        }
    }
    if(num>1){
        um[num]++;
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr(n);
        unordered_map<ll,ll> um;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            getPrimeFactors(arr[i],um);
        }
        bool flag =true;
        for(auto i: um){
            if((i.second%n)!=0){
                flag= false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}