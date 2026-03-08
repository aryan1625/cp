#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int n){
    vector<int> ans;
    long long int x = 1;
    ans.push_back(x);
    while(x<=n){
        x = (x+1)*2;
        if (x>n) break;
        ans.push_back(x);
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> val = solve(n);
        auto it = lower_bound(val.begin(),val.end(),n);
        cout<<(it-val.begin())+1<<endl;       
    }
    return 0;
}