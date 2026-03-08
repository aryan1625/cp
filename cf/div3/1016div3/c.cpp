#include<bits/stdc++.h>
using namespace std;
// vector<int> sieve(int n) {
//    vector<int> p(n + 1, 1);
//    p[0] = p[1] = 0; 
//    for (int i = 2; i<=sqrt(n); ++i) {
//        if (p[i] == 1) {
//            for (int j = i * i; j <= n; j += i) {
//                p[j] = 0; 
//            }
//        }
//    }
//    return p;
// }
bool isPrime(long long n) {
    if(n<=1)return false;
    if(n<=3)return true;
    if((n%2==0)||(n%3==0))return false;
    for(long long i=5;i*i<=n;i+=6) {
        if((n%i==0)||(n%(i+2)==0))
            return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    // vector<int> prime = sieve(1e9);
    while(t--){
       long long int x,k;
       cin>>x>>k;
       if(x==1 && k==2){
        cout<<"Yes"<<endl;
        continue;
       }
       if(x==1){
        cout<<"No"<<endl;
        continue;
       }
       if(k>1){
        cout<<"No"<<endl;
        continue;
       }
       if(isPrime(x)){
        cout<<"Yes"<<endl;
       }else{
        cout<<"No"<<endl;
       }


    }
    return 0;
}