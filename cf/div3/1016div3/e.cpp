#include<bits/stdc++.h>
using namespace std;
bool solve(vector<long long> &a,long long int mid,int n,int k){
    if(mid==0)return true;
    vector<int> freq(mid,1);
    int rem  = mid;
    // for(int i=0;i<mid;i++)
    int fnd = 0;
    for(int i=0;i<n;i++){
        // if(st.count(a[i]))st.erase(a[i]);
        // if(st.empty()){
        //     fnd++;
        //     for(int j=0;j<mid;j++)st.insert(j);
        // }
        if (a[i] < mid && freq[a[i]]) {
            freq[a[i]] = 0;
            rem--;
        }
        if (rem == 0) {
            fnd++;
            rem = mid;
            fill(freq.begin(), freq.end(), 1);
        }
    }   
    return fnd>=k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long int st = 0;
        long long int en = n;
        long long int ans = st;
        while(st<=en){
            long long int mid = (st+en)/2;
            if(solve(a,mid,n,k)){
                ans = mid;
                st = mid+1;
            } else {
                en = mid-1;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}