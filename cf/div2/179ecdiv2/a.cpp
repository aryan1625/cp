#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        int val = log2(n);
        cout<<3+val*2<<endl;
    }
    return 0;
}