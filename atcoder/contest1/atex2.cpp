#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,p;
    cin>>n>>t>>p;
    map<int,int> m;
    vector<int> l(n,0);
    for(int i=0;i<n;i++){
        cin>>l[i];
        if(l[i]>=t)m[0]++;
        else{
            m[t-l[i]]++;
        }
    }
    int ans = 0;
    int val = 0;
    for(auto i: m){
        val += i.second;
        if(val>=p){
            ans = i.first;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}