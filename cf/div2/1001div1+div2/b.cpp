#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool flag = true;
        for(int i=0;i<n;i++){
            if(arr[i]<=2*i || arr[i]<=2*(n-i-1)){
                flag = false;
                break;
            }
            
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        

    }
    return 0;
}