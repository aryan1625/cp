#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        unordered_set<int> us1;
        unordered_set<int> us2;
        for(int i=0;i<n;i++){
            cin>>a[i];
            us1.insert(a[i]);  
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            us2.insert(b[i]);
        }
        if(us1.size()*us2.size()>=3)cout<<"Yes"<<endl;
        else{
            cout<<"No"<<endl;   
        }
    }
    return 0;
}