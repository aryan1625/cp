#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                if(nums[i+1]==1){
                    ans = -1;
                    break;
                }
                else{
                    nums[i] = sqrt(nums[i]);
                    ans++;
                    i++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}