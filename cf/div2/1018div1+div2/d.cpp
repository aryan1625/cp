#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<ll,ll>> arr(n);
        int x = 0,y = 0;
        //key observation the column which has odd number of lightbulbs is the column that contains our answer
        //key observation 2
        //for x+y line also we toggle two light bulbs wtf?!?!?!?!
        //this is so fucking coooooooolll!?!?!?!!!!!
        //so we can get x by checking which x line has odd
        //and y by checking which x+y line has odd number of lightbulbs
        unordered_map<int,int> um;
        unordered_map<int,int> um2;
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
            um[arr[i].first]++;
            um2[arr[i].second+arr[i].first]++;
        }
        int val = 0;
        for(auto i: um){
            if((i.second&1)==1){
                x = i.first;
                break;
            }
        }
        for(auto i: um2){
            if((i.second&1)==1){
                y = i.first-x;
                break;
            }
        }
        cout<<x<<" "<<y<<endl;

        
    }
    return 0;
}