#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<ll>> vec;
        unordered_map<ll,ll> um;
        //intuition we want to find ki if there is one case in which 
        //if we remove the number from the bitwise or of all elements
        //and still ans is same
        //this can be done by counting the number of set bits in all numbers
        //and checking for each number if the count of that set bit is more than 2
        //for all bits
       for(int i=0;i<n;i++){
           ll k;
           cin>>k;
           vector<ll> vecj(k);
           ll val2 = 0;
           vec.push_back(vecj);
           for(int j=0;j<k;j++){
               cin>>vec[i][j];
               um[vec[i][j]]++;
            }
        }
        bool flag = false;
        for(int i=0;i<n;i++){
            bool flag2 = true;
            for(int j=0;j<vec[i].size();j++){
                if(um[vec[i][j]]<2){
                    flag2 = false;
                    break;
                }
            }
            if(flag2){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}