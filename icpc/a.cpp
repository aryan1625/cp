#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            cin>>pos[i];
        }
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i].first;
            vec[i].second = pos[i];
        }
        sort(pos.begin(),pos.end());
        sort(vec.begin(),vec.end());
        long long int ans = 0;
        priority_queue<long long int> pq;
        for(int i=0;i<n;i++){
            long long int pot = 0;
            long long int val = vec[i].first;
            auto it = lower_bound(pos.begin(),pos.end(),vec[i].second);
            auto it2 = it+1;
            // auto it3 = it-1;
            long long int val2 = INT_MAX;
            if(it2!=pos.end()){
                val = min(val,(long long int)vec[it2-pos.begin()].first);
                val2 = min(val2,(long long int)abs(vec[i].second-(*it2)));
            }
            if(it!=pos.begin()){
                it--;
                val = min(val,(long long int)vec[it-pos.begin()].first);
                val2 = min(val2,(long long int)abs(vec[i].second-(*it)));
            }
            pot+=val*val2;
            if(pq.size()<n-1){
                pq.push(pot);
            }else{
                if(pot<pq.top()){
                    pq.pop();
                    pq.push(pot);
                }
            }
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}