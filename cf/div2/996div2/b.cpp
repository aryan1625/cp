#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> arr1(n);
        vector<long long int> arr2(n);
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        int flag = 0;
        int diff = 0;
        string ans;
        for(int i=0;i<n;i++){
            if(arr1[i]<arr2[i]){
                if(flag==1){
                    flag = 2;
                    break;
                }else{
                    diff = arr2[i]-arr1[i];
                    flag++;
                }
            }   
        }
        if(flag==0){
            cout<<"Yes"<<endl;
        }else if(flag==2){
            cout<<"No"<<endl;
        }else{
            for(int i=0;i<n;i++){
                if(arr2[i]>arr1[i])continue;
                if(arr1[i]-arr2[i]<diff){
                    flag = 2;
                    break;
                }
            }
            if(flag==2){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }   
        }
    }
    return 0;
}