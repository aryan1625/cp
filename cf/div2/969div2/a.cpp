#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int ev = 0,od = 0;
        if(l&1){
            od = (r-l)/2+1;
            ev = r-l+1-od;
        }else{
            od = (r-l-1)/2+1;
            ev = r-l+1-od;
        }
        cout<<min(ev,od/2)<<endl;
    }
    return 0;
}