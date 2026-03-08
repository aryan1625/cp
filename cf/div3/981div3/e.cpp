#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<bool> visited(n + 1, false);
        
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        
        int swaps_needed = 0;
        
        // Finding all cycles in the permutation
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int cycle_length = 0;
                int x = i;
                
                // Traverse the cycle starting from index i
                while (!visited[x]) {
                    visited[x] = true;
                    x = p[x];
                    cycle_length++;
                }
                
                // For cycles longer than 2, we need to perform cycle_length - 1 swaps
                if (cycle_length > 1) {
                    swaps_needed += cycle_length - 1;
                }
            }
        }
        
        cout << swaps_needed << endl;
    }
    return 0;
}