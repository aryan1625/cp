#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        for(int i=0;i<5;i++){
            int val = pq.top()+1;
            pq.pop();
            pq.push(val);
        }
        int ans = 1;
        for(int i=0;i<3;i++){
            ans*=pq.top();
            pq.pop();
        }
        cout<<ans<<endl;

    }
    return 0;
}