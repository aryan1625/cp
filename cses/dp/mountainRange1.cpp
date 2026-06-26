#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

vector<int> nGr(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
            st.push(i);
    }
    return ans;
}
vector<int> pGr(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
            st.push(i);
    }
    return ans;
}
using ll = long long;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   vector<int> ng; 
   ng = nGr(arr);
   vector<int> pg; 
   pg = pGr(arr);
   vector<pair<int,int>> vec;
   for(int i=0;i<n;i++){
    vec.push_back({arr[i],i});
   }
   sort(vec.rbegin(),vec.rend());
   int maxi = 1;
   vector<int> dp(n,1);
   for(int i=0;i<n;i++){
    int l1 = pg[vec[i].second];
    int r1 = ng[vec[i].second];
    // cout<<l1<<" "<<r1<<endl;
    if(l1==-1 && r1==-1){
        maxi = max(maxi,dp[vec[i].second]);
        // cout<<"maxi "<<maxi<<endl;
        continue;
    }
    if(l1==-1)dp[vec[i].second] = 1+dp[r1];
    else if(r1==-1)dp[vec[i].second] = 1+dp[l1];
    else{
        dp[vec[i].second] = 1+max(dp[l1],dp[r1]);
    }
    maxi = max(maxi,dp[vec[i].second]);
    // cout<<"maxi "<<maxi<<endl;

}
cout<<maxi<<endl;
    return 0;
}