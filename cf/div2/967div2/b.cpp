#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        if(n%2==0){
            cout<<-1<<endl;
            continue;
        }
        vector<int> arr(n);
        int maxi = n;
        int cnt = 1;
        for(int i=0;i<n;i=i+2){
            arr[i] = cnt;
            cnt++;
            if(i+1<n){
                arr[i+1] = maxi;
                maxi--;
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}