#include<bits/stdc++.h>
using namespace std;
//hello
class Compare {
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b)
    {
        if(a.first==b.first)return a.second>b.second;
        return a.first<b.first;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<k)pq.push({arr[i],i+1});
            else{
                pq.push({arr[i]%k+k,i+1});
            }
        }
        while(!pq.empty()){
            int top = pq.top().first;
            int idx = pq.top().second;
            // cout<<top<<endl;
            top -= k;
            pq.pop();
            if(top<=0){
                cout<<idx<<" ";
            }
            else{
                pq.push({top,idx});
            }
        }
        sort(arr.rbegin(),arr.rend());
        
        cout<<endl;
    }
    return 0;
}   