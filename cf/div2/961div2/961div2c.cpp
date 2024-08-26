#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long int m;
        cin >> n >> m;
        vector<pair<int,int>> arr(n);
        // vector<int> arr2(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i].second;
        }
        
        sort(arr.begin(), arr.end());
        long long int maxi = 0;
        long long int val = 0;
        long long int c = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // val += arr[right].first;
            long long int pt = arr[right].first;
            long long int fl = arr[right].second;
            long long int newVal = (m-c)/pt; 
            if(newVal>fl){
                val += fl*pt;
                c += fl*pt;
            }
            else{
                val += newVal*pt;
                c += newVal*pt;
            }
            while(c > m || (arr[right].first - arr[left].first > 1)) {
                long long int div = (c-m)/arr[left].first;
                if(div>arr[left].second){
                    val -= arr[left].second*arr[left].first;
                    c -= arr[left].second*arr[left].first;
                    left++;
                }
                else{
                    val -= div*arr[left].first;
                    c -= div*arr[left].first;
                    arr[left].second -= div;
                    break;
                }
                // val -= arr[left].first*arr[left].second;
                // c -= arr[left].first*arr[left].second;
                // left++;
            }
            maxi = max(maxi, val);
        }
        cout << maxi << endl;
    }
    return 0;
}