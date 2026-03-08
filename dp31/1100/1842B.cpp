//bitmasking question
#include<bits/stdc++.h>
using namespace std;
bool compare(int x,int val){
    for(int i=0;i<32;i++){
        if(((x>>i)&1)==0 && ((val>>i)&1)==1)return false;
    }
    return true;
}
bool compare2(int x,int val){
    return x==val;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> arrA(n),arrB(n),arrC(n);
        for(int i=0;i<n;i++){
            cin>>arrA[i];
        }
        for(int i=0;i<n;i++){
            cin>>arrB[i];
        }
        for(int i=0;i<n;i++){
            cin>>arrC[i];
        }
        int finalVal = 0;
        int i=0,j=0,k=0;
        bool flag = false;
        while(i<n && j<n && k<n){
            bool flag2 = false;
            if(i<n && compare(x,arrA[i])){
                finalVal|=arrA[i++];
                flag2 = true;
            }
            if(j<n && compare(x,arrB[j])){
                finalVal|=arrB[j++];
                flag2 = true;
            }
            if(k<n && compare(x,arrC[k])){
                finalVal|=arrC[k++];
                flag2 = true;
            }
            if(compare2(x,finalVal)){
                flag = true;
                break;
            }
            if(!flag2){
                break;
            }
        }
        string s = flag?"Yes":"No";
        cout<<s<<endl;
    }
    return 0;
}