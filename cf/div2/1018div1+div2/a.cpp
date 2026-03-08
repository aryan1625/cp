#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> arr(n);
        int left = 1;
        int right = n;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='<'){
                arr[i+1]= left;
                left++;
            }else{
                arr[i+1] = right;
                right--;
            }
        }
        arr[0] = left;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}