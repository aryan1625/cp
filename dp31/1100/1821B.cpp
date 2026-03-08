#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr1(n);
        vector<int> arr2(n);
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        int maxi = 0;
        int len = 1;
        for(int i=1;i<n;i++){
            bool flag = false;
            while(i<n && arr2[i]>=arr2[i-1]){
                if(arr2[i-1]!=arr1[i-1])flag = true;
                i++;
                len++;
            }
            if(flag)maxi = max(len,maxi);
            len = 1;
        }
        len = 1;
        int l = 1;
        int r = 1;
        int l1 = 1;
        int r1 = 1;
        for(int i=1;i<n;i++){
            l1 = i;
            bool flag = false;
            while(i<n && arr2[i]>=arr2[i-1]){
                if(arr2[i-1]!=arr1[i-1])flag = true;
                i++;
                len++;

            }
            r1 = i;
            if(flag && len==maxi){
                l = l1;
                r = r1;
                break;
            }
            len = 1;
        }
        cout<<l<<" "<<r<<endl;
    }
    return 0;
}