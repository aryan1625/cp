    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int t;  
        cin >> t;
        while (t > 0) {
            int n, k;
            cin >> n >> k;
            if (k == 0) {
                cout << 0 << endl;
            } else if (k <= n) {
                cout << 1 << endl;
            } else {
                k -= n;
                int ans = 1;
                int val = n - 1;
                int i = 0;
                while (k > 0) {
                    k -= val;
                    ans++;
                    if (i & 1) val--;
                    i++;
                }
                cout << ans << endl;
            }
            t--;
            }
            return 0;
    }