#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int sum = 0;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if(n/i!=i){
                    sum+=n/i;
                }
                sum+=i;
            }
        }
        sum-=n;
        cout<<sum<<" "<<n<<endl;
        if(sum==n){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}