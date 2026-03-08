#include<bits/stdc++.h>
using namespace std;
// int mergeI(vector<pair<long long int,long long int>> intervals)
// {
//     sort(intervals.begin(), intervals.end(), [](const pair<long long int, long long int>& a,
//                const pair<long long int, long long int>& b)
// {
//     return (a.second < b.second);
// });
//     int ans = 1;
//     long long int r1 = intervals[0].second;
//     for (int i = 1; i < intervals.size(); i++) {
//         long long int l1 = intervals[i].first;
//         long long int r2 = intervals[i].second;
//         if (l1 > r1) {
//             ans++;
//             r1 = r2;
//         }
//     }
//     return ans;
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        
        map<long long int, int> pref;
        long long sum = 0;
        int last = -1;
        int ans = 0;
        pref[0] = -1;
        for (int i=0; i<n; i++) {
            sum+=a[i];
            if (pref.find(sum) != pref.end()) {
                int idx = pref[sum];
                if (idx >= last) {
                    ans++;
                    last = i;
                }
            }
            pref[sum] = i;
        }
        cout<<ans<<endl;
    }
    return 0;
}