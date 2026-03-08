#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a1,a2,a4,a5;
        cin>>a1>>a2>>a4>>a5;
        unordered_set<int> us;
        us.insert(a5-a4);
        us.insert(a4-a2);
        us.insert(a1+a2);
        cout<<4-us.size()<<endl;

    }
    return 0;
}